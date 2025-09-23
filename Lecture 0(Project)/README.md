# Lecture 0 — Projects

This folder contains two C++ console projects:

- Tic Tac Toe (`Tic_Tac_Toe_Game.cpp`)
- Hotel Management (`Hotel_Managment.cpp`)

Both are simple, self-contained programs that build and run on Windows with MinGW g++ and in VS Code using the included build task.

## Overview

- Tic Tac Toe: A two-player console game implementing a classic 3×3 grid. Clean I/O loop, position mapping (1–9), win/draw detection, and replay support.
- Hotel Management: A modernized, class-based CLI app to manage rooms, bookings, and bills. Uses STL containers and portable I/O (no DOS/conio). Persists data to simple `|`-delimited text files (`roomtype.txt`, `record.dat`, `bill.txt`).
- Build/Run: Both programs compile with `g++ -std=c++17` and run directly as Windows console executables. The workspace already has a VS Code build task for quick builds.

## Tic Tac Toe

- Two-player console game with a 3x3 board
- Players alternate turns entering positions 1–9
- Detects wins and draws, allows replay

### Build & Run (PowerShell)

```powershell
Set-Location 'C:\Programming\C++ programming\DSA C++\Lecture 0(Project)'
g++ Tic_Tac_Toe_Game.cpp -O2 -std=c++17 -o Tic_Tac_Toe_Game.exe
./Tic_Tac_Toe_Game.exe
```

### Quick Play

```text
Positions:
1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9

Player X, enter position: 5
Player O, enter position: 1
...
```

## Hotel Management

Modernized C++ console application to manage rooms, bookings, and bills. It uses portable I/O and STL (no DOS/conio dependencies).

### Features

- Add/modify/display/delete rooms (Master menu)
- Current and advance bookings (Check-in menu)
- Checkout with bill generation
- List active customers and bill history

### Data Files (created in the same folder)

- `roomtype.txt` — `roomNumber|roomType|bedType|price|available(1/0)`
- `record.dat` — `roomNumber|name|address|phone|members|checkinDate|nights|perDayCost`
- `bill.txt` — `roomNumber|name|address|phone|members|checkinDate|nights|perDayCost|total`

Example `roomtype.txt`:

```text
101|Deluxe|Queen|2000|1
102|Deluxe|Twin|1800|1
201|Suite|King|3500|0
```

### Build & Run (PowerShell) — Hotel

```powershell
Set-Location 'C:\Programming\C++ programming\DSA C++\Lecture 0(Project)'
g++ Hotel_Managment.cpp -O2 -std=c++17 -o Hotel_Managment.exe
./Hotel_Managment.exe
```

### Quick Start

1. Master → Add: create at least one room
2. Check-in → Current/Advance: create a booking
3. Check-out: finalize a booking and generate a bill
4. Customer Info → Display/Bill display: view current and past records

If prompts do not appear immediately, ensure you are running the `.exe` in a terminal; the program flushes prompts and ties input to output for reliable display.
