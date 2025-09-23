/*
	Hotel Management System (modern C++)

	Overview
	- Rewritten with classes, STL containers, and portable console I/O
	- Replaces legacy DOS/borland APIs (conio, gotoxy, textcolor)
	- Keeps the same top-level features and menu flow as the original

	Persistence (text files, one record per line, fields delimited by '|')
	- roomtype.txt: rooms database
			roomNumber|roomType|bedType|price|available(1 or 0)
	- record.dat: active bookings (current/advance check-in)
			roomNumber|name|address|phone|members|checkinDate|nights|perDayCost
	- bill.txt: finalized bills (appended per checkout)
			roomNumber|name|address|phone|members|checkinDate|nights|perDayCost|total

	Quick Start
	1) Run the program and go to Master -> Add to create rooms
	2) Check-in -> Current or Advance to create a booking
	3) Check-out to finalize and move the booking to bill history
	4) Customer Info -> Display/Bill display to inspect active and past records

	Notes
	- Input is validated (numbers are re-prompted). Leave blank in modify menus
		to keep existing values.
	- Files are small, so the app loads/saves entire maps atomically for simplicity.
*/

#include <bits/stdc++.h>
using namespace std;

// Represents an individual room entry in the hotel inventory
struct Room {
	int number = 0;
	string type;
	string bed;
	double price = 0;
	bool available = true;
};

// Represents an active booking/reservation for a room
struct Booking {
	int roomNumber = 0;
	string name;
	string address;
	string phone;
	int members = 0;
	string checkinDate; // free-format (e.g., DD/MM/YYYY)
	int nights = 0;
	double perDayCost = 0;
};

// Represents a finalized bill created at checkout
struct Bill {
	int roomNumber = 0;
	string name;
	string address;
	string phone;
	int members = 0;
	string checkinDate;
	int nights = 0;
	double perDayCost = 0;
	double total = 0;
};

// Small I/O helpers for trimming, splitting and parsing
namespace io {
	static inline string trim(const string &s) {
		size_t a = s.find_first_not_of(" \t\r\n");
		size_t b = s.find_last_not_of(" \t\r\n");
		if (a == string::npos) return "";
		return s.substr(a, b - a + 1);
	}
	static inline vector<string> split(const string &s, char delim) {
		vector<string> out; string item; stringstream ss(s);
		while (getline(ss, item, delim)) out.push_back(item);
		return out;
	}
	template <class T>
	static inline T parseOr(const string &s, const T &fallback) {
		T v{}; stringstream ss(s); if (ss >> v) return v; return fallback;
	}
}

// Store: stateless helper for reading/writing the text files
class Store {
public:
	static bool loadRooms(const string &file, unordered_map<int, Room> &rooms) {
		rooms.clear();
		ifstream fin(file);
		if (!fin.is_open()) return false;
		string line;
		while (getline(fin, line)) {
			line = io::trim(line);
			if (line.empty()) continue;
			auto parts = io::split(line, '|');
			if (parts.size() < 5) continue;
			Room r;
			r.number = io::parseOr<int>(parts[0], 0);
			r.type = parts[1];
			r.bed = parts[2];
			r.price = io::parseOr<double>(parts[3], 0);
			r.available = io::parseOr<int>(parts[4], 1) != 0;
			if (r.number > 0) rooms[r.number] = r;
		}
		return true;
	}

	static bool saveRooms(const string &file, const unordered_map<int, Room> &rooms) {
		vector<int> keys; keys.reserve(rooms.size());
		for (auto &kv : rooms) keys.push_back(kv.first);
		sort(keys.begin(), keys.end());
		ofstream fout(file, ios::trunc);
		if (!fout.is_open()) return false;
		for (int k : keys) {
			const Room &r = rooms.at(k);
			fout << r.number << '|' << r.type << '|' << r.bed << '|' << r.price << '|' << (r.available ? 1 : 0) << "\n";
		}
		return true;
	}

	static bool loadBookings(const string &file, unordered_map<int, Booking> &bookings) {
		bookings.clear();
		ifstream fin(file);
		if (!fin.is_open()) return false;
		string line;
		while (getline(fin, line)) {
			line = io::trim(line);
			if (line.empty()) continue;
			auto p = io::split(line, '|');
			if (p.size() < 8) continue;
			Booking c;
			c.roomNumber = io::parseOr<int>(p[0], 0);
			c.name = p[1];
			c.address = p[2];
			c.phone = p[3];
			c.members = io::parseOr<int>(p[4], 0);
			c.checkinDate = p[5];
			c.nights = io::parseOr<int>(p[6], 0);
			c.perDayCost = io::parseOr<double>(p[7], 0);
			if (c.roomNumber > 0) bookings[c.roomNumber] = c;
		}
		return true;
	}

	static bool saveBookings(const string &file, const unordered_map<int, Booking> &bookings) {
		vector<int> keys; keys.reserve(bookings.size());
		for (auto &kv : bookings) keys.push_back(kv.first);
		sort(keys.begin(), keys.end());
		ofstream fout(file, ios::trunc);
		if (!fout.is_open()) return false;
		for (int k : keys) {
			const Booking &c = bookings.at(k);
			fout << c.roomNumber << '|' << c.name << '|' << c.address << '|' << c.phone << '|' << c.members << '|' << c.checkinDate << '|' << c.nights << '|' << c.perDayCost << "\n";
		}
		return true;
	}

	static bool appendBill(const string &file, const Bill &bill) {
		ofstream fout(file, ios::app);
		if (!fout.is_open()) return false;
		fout << bill.roomNumber << '|' << bill.name << '|' << bill.address << '|' << bill.phone << '|' << bill.members<< '|' << bill.checkinDate << '|' << bill.nights << '|' << bill.perDayCost << '|' << bill.total << "\n";
		return true;
	}

	static vector<Bill> loadBills(const string &file) {
		vector<Bill> out;
		ifstream fin(file);
		if (!fin.is_open()) return out;
		string line;
		while (getline(fin, line)) {
			line = io::trim(line);
			if (line.empty()) continue;
			auto p = io::split(line, '|');
			if (p.size() < 9) continue;
			Bill b;
			b.roomNumber = io::parseOr<int>(p[0], 0);
			b.name = p[1];
			b.address = p[2];
			b.phone = p[3];
			b.members = io::parseOr<int>(p[4], 0);
			b.checkinDate = p[5];
			b.nights = io::parseOr<int>(p[6], 0);
			b.perDayCost = io::parseOr<double>(p[7], 0);
			b.total = io::parseOr<double>(p[8], 0);
			out.push_back(move(b));
		}
		return out;
	}
};

// Hotel: application controller holding in-memory state and all menus
class Hotel {
	unordered_map<int, Room> rooms;
	unordered_map<int, Booking> bookings;

	const string roomsFile = "roomtype.txt";
	const string bookingsFile = "record.dat";
	const string billsFile = "bill.txt";

public:
	Hotel() { load(); }

	void load() {
		Store::loadRooms(roomsFile, rooms);
		Store::loadBookings(bookingsFile, bookings);
	}
	void persist() {
		Store::saveRooms(roomsFile, rooms);
		Store::saveBookings(bookingsFile, bookings);
	}

	void run();

private:
	static int readInt(const string &prompt) {
		while (true) {
			cout << prompt << flush;
			string s; if (!getline(cin, s)) return 0; s = io::trim(s);
			if (s.empty()) continue;
			try { return stoi(s); } catch (...) { cout << "Invalid number. Try again.\n"; }
		}
	}
	static double readDouble(const string &prompt) {
		while (true) {
			cout << prompt << flush;
			string s; if (!getline(cin, s)) return 0; s = io::trim(s);
			if (s.empty()) continue;
			try { return stod(s); } catch (...) { cout << "Invalid number. Try again.\n"; }
		}
	}
	static string readLine(const string &prompt) {
		cout << prompt << flush;
		string s; getline(cin, s); return io::trim(s);
	}

	void printHeader(const string &title) {
		cout << string(60, '*') << "\n" << title << "\n" << string(60, '*') << "\n";
	}

	void menuCheckin();
	void menuMaster();
	void menuCustomer();

	void showAvailability();
	void currentBooking();
	void advanceBooking();
	void checkout();

	void roomAdd();
	void roomModify();
	void roomDisplay();
	void roomDelete();

	void customerModify();
	void customerDisplay();
	void billDisplay();
};

// Print table of rooms with availability and pricing
void Hotel::showAvailability() {
	printHeader("ROOM AVAILABILITY");
	cout << left << setw(10) << "Room" << setw(15) << "Type" << setw(12) << "Bed" << setw(10) << "Price" << setw(12) << "Status" << "\n";
	cout << string(60, '-') << "\n";
	vector<int> keys; for (auto &kv : rooms) keys.push_back(kv.first);
	sort(keys.begin(), keys.end());
	for (int k : keys) {
		const Room &r = rooms[k];
		cout << left << setw(10) << r.number << setw(15) << r.type << setw(12) << r.bed<< setw(10) << fixed << setprecision(2) << r.price << setw(12) << (r.available ? "Available" : "Booked") << "\n";
	}
	cout << "\n";
}

// Create a booking using today's date and mark room unavailable
void Hotel::currentBooking() {
	showAvailability();
	vector<int> freeRooms;
	for (auto &kv : rooms) if (kv.second.available) freeRooms.push_back(kv.first);
	if (freeRooms.empty()) { cout << "No rooms available.\n"; return; }
	int rno = readInt("Enter room number (0 to cancel): ");
	if (rno == 0) return;
	auto it = rooms.find(rno);
	if (it == rooms.end() || !it->second.available) { cout << "Invalid/unavailable room.\n"; return; }
	Booking c;
	c.roomNumber = rno;
	c.perDayCost = it->second.price;
	c.name = readLine("Name: ");
	c.members = readInt("No. of family members: ");
	c.address = readLine("Address: ");
	c.nights = readInt("Number of nights: ");
	c.phone = readLine("Phone: ");
	time_t t = time(nullptr); tm *lt = localtime(&t);
	char buf[16]; strftime(buf, sizeof(buf), "%d/%m/%Y", lt);
	c.checkinDate = buf;
	string yn = io::trim(readLine("Save booking (Y/N): "));
	if (!yn.empty() && (yn[0] == 'Y' || yn[0] == 'y')) {
		bookings[rno] = c; rooms[rno].available = false; persist();
		cout << "Booking saved. Have a nice day!\n";
	}
}

// Create a reservation with a user-provided future check-in date
void Hotel::advanceBooking() {
	showAvailability();
	int rno = readInt("Enter room number to reserve (0 to cancel): ");
	if (rno == 0) return;
	auto it = rooms.find(rno);
	if (it == rooms.end() || !it->second.available) { cout << "Invalid/unavailable room.\n"; return; }
	Booking c;
	c.roomNumber = rno;
	c.perDayCost = it->second.price;
	c.name = readLine("Name: ");
	c.members = readInt("No. of family members: ");
	c.checkinDate = readLine("Enter check-in date (DD/MM/YYYY): ");
	c.address = readLine("Address: ");
	c.phone = readLine("Phone: ");
	c.nights = max(1, readInt("Estimated number of nights: "));
	string yn = io::trim(readLine("Save reservation (Y/N): "));
	if (!yn.empty() && (yn[0] == 'Y' || yn[0] == 'y')) {
		bookings[rno] = c; rooms[rno].available = false; persist();
		cout << "Reservation saved. See you soon!\n";
	}
}

// Finalize a booking into a bill and free the room
void Hotel::checkout() {
	if (bookings.empty()) { cout << "No active bookings.\n"; return; }
	int rno = readInt("Enter room number to generate bill: ");
	auto it = bookings.find(rno);
	if (it == bookings.end()) { cout << "No booking found for this room.\n"; return; }
	const Booking &c = it->second;
	double base = c.nights * c.perDayCost;
	double total = base; // extendable for taxes/extras
	cout << fixed << setprecision(2);
	cout << "\n--- BILL ---\n";
	cout << "Room: " << c.roomNumber << "\nName: " << c.name << "\nMembers: " << c.members<< "\nAddress: " << c.address << "\nPhone: " << c.phone<< "\nNights: " << c.nights << "\nPer-day: " << c.perDayCost<< "\nSubtotal: " << base << "\nGrand Total: " << total << "\n";
	string yn = io::trim(readLine("Confirm payment (Y/N): "));
	if (!yn.empty() && (yn[0] == 'Y' || yn[0] == 'y')) {
		Bill b;
		b.roomNumber = c.roomNumber; b.name = c.name; b.address = c.address; b.phone = c.phone;
		b.members = c.members; b.checkinDate = c.checkinDate; b.nights = c.nights;
		b.perDayCost = c.perDayCost; b.total = total;
		Store::appendBill(billsFile, b);
		rooms[rno].available = true;
		bookings.erase(it);
		persist();
		cout << "Payment recorded. Checkout complete.\n";
	}
}

// Master: add a new room into the inventory
void Hotel::roomAdd() {
	Room r;
	r.number = readInt("Room number: ");
	if (r.number <= 0) { cout << "Invalid room number.\n"; return; }
	if (rooms.count(r.number)) { cout << "Room already exists.\n"; return; }
	r.type = readLine("Room type: ");
	r.bed = readLine("Bed type: ");
	r.price = readDouble("Room price: ");
	r.available = true;
	string yn = io::trim(readLine("Save (Y/N): "));
	if (!yn.empty() && (yn[0] == 'Y' || yn[0] == 'y')) {
		rooms[r.number] = r; persist();
		cout << "Room added.\n";
	}
}

// Master: modify basic room attributes (type/bed/price)
void Hotel::roomModify() {
	int rno = readInt("Enter room number to modify: ");
	auto it = rooms.find(rno);
	if (it == rooms.end()) { cout << "Room not found.\n"; return; }
	Room r = it->second;
	cout << "Leave blank to keep existing.\n";
	{
		string s = readLine("Room type [" + r.type + "]: "); if (!io::trim(s).empty()) r.type = s;
	}
	{
		string s = readLine("Bed type [" + r.bed + "]: "); if (!io::trim(s).empty()) r.bed = s;
	}
	{
		string s = readLine("Price [" + to_string(r.price) + "]: ");
		s = io::trim(s); if (!s.empty()) { try { r.price = stod(s); } catch (...) {} }
	}
	string yn = io::trim(readLine("Save changes (Y/N): "));
	if (!yn.empty() && (yn[0] == 'Y' || yn[0] == 'y')) { rooms[rno] = r; persist(); cout << "Room updated.\n"; }
}

// Master: display all rooms and status
void Hotel::roomDisplay() {
	printHeader("ROOM DETAILS");
	cout << left << setw(10) << "Room" << setw(15) << "Type" << setw(12) << "Bed"<< setw(10) << "Price" << setw(12) << "Status" << "\n";
	cout << string(60, '-') << "\n";
	vector<int> keys; for (auto &kv : rooms) keys.push_back(kv.first);
	sort(keys.begin(), keys.end());
	for (int k : keys) {
		const Room &r = rooms[k];
		cout << left << setw(10) << r.number << setw(15) << r.type << setw(12) << r.bed<< setw(10) << fixed << setprecision(2) << r.price << setw(12) << (r.available ? "Available" : "Booked") << "\n";
	}
}

// Master: delete room if not currently booked
void Hotel::roomDelete() {
	int rno = readInt("Enter room number to delete: ");
	if (!rooms.count(rno)) { cout << "Room not found.\n"; return; }
	if (bookings.count(rno)) { cout << "Cannot delete: room currently booked.\n"; return; }
	string yn = io::trim(readLine("Confirm delete (Y/N): "));
	if (!yn.empty() && (yn[0] == 'Y' || yn[0] == 'y')) {
		rooms.erase(rno); persist(); cout << "Room deleted.\n";
	}
}

// Customer menu: modify fields of an existing booking
void Hotel::customerModify() {
	int rno = readInt("Enter room number to modify booking: ");
	auto it = bookings.find(rno);
	if (it == bookings.end()) { cout << "No booking found.\n"; return; }
	Booking c = it->second;
	cout << "Leave blank to keep existing.\n";
	{
		string s = readLine("Name [" + c.name + "]: "); if (!io::trim(s).empty()) c.name = s;
	}
	{
		string s = readLine("Members [" + to_string(c.members) + "]: "); s = io::trim(s); if (!s.empty()) { try { c.members = stoi(s); } catch (...) {} }
	}
	{
		string s = readLine("Address [" + c.address + "]: "); if (!io::trim(s).empty()) c.address = s;
	}
	{
		string s = readLine("Nights [" + to_string(c.nights) + "]: "); s = io::trim(s); if (!s.empty()) { try { c.nights = stoi(s); } catch (...) {} }
	}
	{
		string s = readLine("Phone [" + c.phone + "]: "); if (!io::trim(s).empty()) c.phone = s;
	}
	string yn = io::trim(readLine("Save changes (Y/N): "));
	if (!yn.empty() && (yn[0] == 'Y' || yn[0] == 'y')) { bookings[rno] = c; persist(); cout << "Booking updated.\n"; }
}

// Customer menu: list active bookings
void Hotel::customerDisplay() {
	printHeader("CUSTOMER DETAILS");
	cout << left << setw(6) << "Room" << setw(18) << "Name" << setw(16) << "Phone" << setw(6) << "Days" << setw(10) << "Cost" << "\n";
	cout << string(60, '-') << "\n";
	vector<int> keys; for (auto &kv : bookings) keys.push_back(kv.first);
	sort(keys.begin(), keys.end());
	for (int k : keys) {
		const Booking &c = bookings[k];
		cout << left << setw(6) << c.roomNumber << setw(18) << c.name << setw(16) << c.phone<< setw(6) << c.nights << setw(10) << fixed << setprecision(2) << c.perDayCost << "\n";
	}
}

// Customer menu: list historical bills from bill.txt
void Hotel::billDisplay() {
	auto bills = Store::loadBills(billsFile);
	if (bills.empty()) { cout << "No bills found.\n"; return; }
	printHeader("BILL HISTORY");
	cout << left << setw(6) << "Room" << setw(16) << "Name" << setw(10) << "Days" << setw(10) << "PerDay" << setw(12) << "Total" << "\n";
	cout << string(60, '-') << "\n";
	for (const auto &b : bills) {
		cout << left << setw(6) << b.roomNumber << setw(16) << b.name << setw(10) << b.nights<< setw(10) << fixed << setprecision(2) << b.perDayCost << setw(12) << b.total << "\n";
	}
}

// Submenu for check-in related actions
void Hotel::menuCheckin() {
	while (true) {
		cout << "\n--- CHECK-IN ---\n1. Current booking\n2. Advance booking\n3. Return\nChoice: " << flush;
		string ch; getline(cin, ch); ch = io::trim(ch);
		if (ch == "1") currentBooking();
		else if (ch == "2") advanceBooking();
		else if (ch == "3" || ch.empty()) return;
		else cout << "Invalid choice.\n";
	}
}

// Submenu for room inventory (master) actions
void Hotel::menuMaster() {
	while (true) {
		cout << "\n--- MASTER: ROOM OPTIONS ---\n1. Add\n2. Modify\n3. Display\n4. Delete\n5. Return\nChoice: " << flush;
		string ch; getline(cin, ch); ch = io::trim(ch);
		if (ch == "1") roomAdd();
		else if (ch == "2") roomModify();
		else if (ch == "3") roomDisplay();
		else if (ch == "4") roomDelete();
		else if (ch == "5" || ch.empty()) return;
		else cout << "Invalid choice.\n";
	}
}

// Submenu for customer and bills
void Hotel::menuCustomer() {
	while (true) {
		cout << "\n--- CUSTOMER OPTIONS ---\n1. Modify\n2. Display\n3. Bill display\n4. Return\nChoice: " << flush;
		string ch; getline(cin, ch); ch = io::trim(ch);
		if (ch == "1") customerModify();
		else if (ch == "2") customerDisplay();
		else if (ch == "3") billDisplay();
		else if (ch == "4" || ch.empty()) return;
		else cout << "Invalid choice.\n";
	}
}

// Main loop: presents top-level menu and dispatches
void Hotel::run() {
	cout << "\nHOTEL MANAGEMENT SYSTEM\n";
	cout << "-----------------------\n";
	while (true) {
		cout << "\nMAIN MENU\n1. Check-in\n2. Check-out\n3. Customer info\n4. Master\n5. Exit\nChoice: " << flush;
		string ch; getline(cin, ch); ch = io::trim(ch);
		if (ch == "1") menuCheckin();
		else if (ch == "2") checkout();
		else if (ch == "3") menuCustomer();
		else if (ch == "4") menuMaster();
		else if (ch == "5") break;
		else cout << "Invalid choice.\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(&cout);
	Hotel h; 
    h.run();
	
    return 0;
}

/*
HOTEL MANAGEMENT SYSTEM
-----------------------

MAIN MENU
1. Check-in
2. Check-out
3. Customer info
4. Master
5. Exit
Choice: 4

--- MASTER: ROOM OPTIONS ---
1. Add
2. Modify
3. Display
4. Delete
5. Return
Choice: 3
************************************************************
ROOM DETAILS
------------------------------------------------------------
Room      Type           Bed         Price     Status
101       Deluxe         Queen       2000.00   Available
102       Deluxe         Twin        1800.00   Available
201       Suite          King        3500.00   Booked

Choice: 5

MAIN MENU
1. Check-in
2. Check-out
3. Customer info
4. Master
5. Exit
Choice: 1

--- CHECK-IN ---
1. Current booking
2. Advance booking
3. Return
Choice: 1
ROOM AVAILABILITY
------------------------------------------------------------
Room      Type           Bed         Price     Status
101       Deluxe         Queen       2000.00   Available
102       Deluxe         Twin        1800.00   Available
Enter room number (0 to cancel): 101
Name: Asha Verma
No. of family members: 3
Address: Pune
Number of nights: 2
Phone: 9876543210
Save booking (Y/N): Y
Booking saved. Have a nice day!

MAIN MENU
1. Check-in
2. Check-out
3. Customer info
4. Master
5. Exit
Choice: 2
Enter room number to generate bill: 101

--- BILL ---
Room: 101
Name: Asha Verma
Members: 3
Address: Pune
Phone: 9876543210
Nights: 2
Per-day: 2000.00
Subtotal: 4000.00
Grand Total: 4000.00
Confirm payment (Y/N): Y
Payment recorded. Checkout complete.

MAIN MENU
1. Check-in
2. Check-out
3. Customer info
4. Master
5. Exit
Choice: 3

--- CUSTOMER OPTIONS ---
1. Modify
2. Display
3. Bill display
4. Return
Choice: 3
************************************************************
BILL HISTORY
------------------------------------------------------------
Room  Name            Days      PerDay    Total
101   Asha Verma      2         2000.00   4000.00

Choice: 4

MAIN MENU
1. Check-in
2. Check-out
3. Customer info
4. Master
5. Exit
Choice: 5
*/ 