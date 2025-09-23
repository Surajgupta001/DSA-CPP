/*
Design Movie Rental System - [Leetcode - 1912(Hard)]
------------------------------------------------------
You have a movie renting company consisting of n shops. You want to implement a renting system that supports searching for, booking, and returning movies. The system should also support generating a report of the currently rented movies.

Each movie is given as a 2D integer array entries where entries[i] = [shopi, moviei, pricei] indicates that there is a copy of movie moviei at shop shopi with a rental price of pricei. Each shop carries at most one copy of a movie moviei.

The system should support the following functions:

Search: Finds the cheapest 5 shops that have an unrented copy of a given movie. The shops should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopi should appear first. If there are less than 5 matching shops, then all of them should be returned. If no shop has an unrented copy, then an empty list should be returned.
Rent: Rents an unrented copy of a given movie from a given shop.
Drop: Drops off a previously rented copy of a given movie at a given shop.
Report: Returns the cheapest 5 rented movies (possibly of the same movie ID) as a 2D list res where res[j] = [shopj, moviej] describes that the jth cheapest rented movie moviej was rented from the shop shopj. The movies in res should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopj should appear first, and if there is still tie, the one with the smaller moviej should appear first. If there are fewer than 5 rented movies, then all of them should be returned. If no movies are currently being rented, then an empty list should be returned.
Implement the MovieRentingSystem class:

MovieRentingSystem(int n, int[][] entries) Initializes the MovieRentingSystem object with n shops and the movies in entries.
List<Integer> search(int movie) Returns a list of shops that have an unrented copy of the given movie as described above.
void rent(int shop, int movie) Rents the given movie from the given shop.
void drop(int shop, int movie) Drops off a previously rented movie at the given shop.
List<List<Integer>> report() Returns a list of cheapest rented movies as described above.
Note: The test cases will be generated such that rent will only be called if the shop has an unrented copy of the movie, and drop will only be called if the shop had previously rented out the movie.

Example 1:

Input
["MovieRentingSystem", "search", "rent", "rent", "report", "drop", "search"]
[[3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]], [1], [0, 1], [1, 2], [], [1, 2], [2]]
Output
[null, [1, 0, 2], null, null, [[0, 1], [1, 2]], null, [0, 1]]

Explanation
MovieRentingSystem movieRentingSystem = new MovieRentingSystem(3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]);
movieRentingSystem.search(1);  // return [1, 0, 2], Movies of ID 1 are unrented at shops 1, 0, and 2. Shop 1 is cheapest; shop 0 and 2 are the same price, so order by shop number.
movieRentingSystem.rent(0, 1); // Rent movie 1 from shop 0. Unrented movies at shop 0 are now [2,3].
movieRentingSystem.rent(1, 2); // Rent movie 2 from shop 1. Unrented movies at shop 1 are now [1].
movieRentingSystem.report();   // return [[0, 1], [1, 2]]. Movie 1 from shop 0 is cheapest, followed by movie 2 from shop 1.
movieRentingSystem.drop(1, 2); // Drop off movie 2 at shop 1. Unrented movies at shop 1 are now [1,2].
movieRentingSystem.search(2);  // return [0, 1]. Movies of ID 2 are unrented at shops 0 and 1. Shop 0 is cheapest, followed by shop 1.
 

Constraints:

1 <= n <= 3 * 105
1 <= entries.length <= 105
0 <= shopi < n
1 <= moviei, pricei <= 104
Each shop carries at most one copy of a movie moviei.
At most 105 calls in total will be made to search, rent, drop and report.
*/ 

/*
Design Movie Rental System - [Leetcode - 1912(Hard)]
------------------------------------------------------
You have n shops and entries = [shop, movie, price] describing one copy of a movie at a shop.
Support:
- search(movie): cheapest up to 5 shops that currently have an UNRENTED copy of 'movie' sorted by (price asc, shop asc).
- rent(shop, movie): mark that copy as RENTED.
- drop(shop, movie): mark that copy as UNRENTED again.
- report(): cheapest up to 5 currently RENTED copies sorted by (price asc, shop asc, movie asc).

Data structures used:
- availableMovies[movie] -> ordered set of {price, shop} for fast top-5 by (price, shop).
- movieToPrice[movie]    -> ordered set of {shop, price} to retrieve price by (shop) quickly.
- rentedMovies           -> ordered set of {price, shop, movie} to report top-5 rented by tie-breakers.

Note:
- We never store duplicates: each (shop, movie) appears once.
- We rely on set ordering (lexicographic for pair/tuple) for tie-breaking.
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <tuple>
#include <climits>
#include <algorithm>
using namespace std;

class MovieRentingSystem {
public:
    // For each movie, stores all currently UNRENTED copies sorted by (price, shop)
    unordered_map<int, set<pair<int, int>>> availableMovies;

    // For each movie, map shops to price using an ordered set of (shop, price)
    // This lets us find the price for a given (movie, shop) via lower_bound
    unordered_map<int, set<pair<int, int>>> movieToPrice;

    // All currently RENTED copies sorted by (price, shop, movie) to satisfy report order
    set<tuple<int, int, int>> rentedMovies;

    // Build initial state: every entry is initially UNRENTED
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &entry : entries) {
            int shop  = entry[0];
            int movie = entry[1];
            int price = entry[2];
            availableMovies[movie].insert({price, shop}); // ready for search()
            movieToPrice[movie].insert({shop, price});    // lookup price by shop when renting/dropping
        }
    }
    
    // Return up to 5 shops with an UNRENTED copy of 'movie' by (price asc, shop asc)
    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;
        if (availableMovies.find(movie) != availableMovies.end()) {
            // availableMovies[movie] is already sorted by (price, shop)
            for (auto& p : availableMovies[movie]) {
                int /*price*/ _ = p.first;
                int shop = p.second;
                result.push_back(shop);
                if (count++ >= 5) break; // only top 5
            }
        }
        return result;
    }
    
    // Rent an UNRENTED copy: remove from available, add to rented
    void rent(int shop, int movie) {
        // Find price for (shop, movie) via (shop, price) set
        auto itr = movieToPrice[movie].lower_bound({shop, INT_MIN});
        int price = itr->second;

        // Move this copy from available -> rented
        availableMovies[movie].erase({price, shop});
        rentedMovies.insert({price, shop, movie});
    }
    
    // Drop a RENTED copy: remove from rented, add back to available
    void drop(int shop, int movie) {
        // Find price for (shop, movie)
        auto itr = movieToPrice[movie].lower_bound({shop, INT_MIN});
        int price = itr->second;

        // Move this copy from rented -> available
        availableMovies[movie].insert({price, shop});
        rentedMovies.erase({price, shop, movie});
    }
    
    // Return up to 5 currently RENTED copies sorted by (price asc, shop asc, movie asc)
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;

        for (auto &entry : rentedMovies) {
            int price = get<0>(entry);
            int shop  = get<1>(entry);
            int movie = get<2>(entry);
            result.push_back({shop, movie});
            if (++count >= 5) break; // only top 5
        }
        return result;
    }
};

/*
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
*/

int main() {
    // Demo based on the problem example
    vector<vector<int>> entries = {
        {0, 1, 5}, {0, 2, 6}, {0, 3, 7},
        {1, 1, 4}, {1, 2, 7},
        {2, 1, 5}
    };
    MovieRentingSystem movieRentingSystem(3, entries);
    
    // Search unrented copies of movie 1: expect shops [1, 0, 2]
    vector<int> searchResult = movieRentingSystem.search(1);
    cout << "Search(1): ";
    for (int shop : searchResult) cout << shop << " ";
    cout << endl;

    // Rent (0,1) and (1,2)
    movieRentingSystem.rent(0, 1);
    movieRentingSystem.rent(1, 2);

    // Report top rented: expect [[0,1], [1,2]] by price asc, then shop, then movie
    vector<vector<int>> reportResult = movieRentingSystem.report();
    cout << "Report(): ";
    for (const auto& entry : reportResult) {
        cout << "[" << entry[0] << ", " << entry[1] << "] ";
    }
    cout << endl;

    // Drop (1,2) back
    movieRentingSystem.drop(1, 2);

    // Search unrented copies of movie 2: expect shops [0, 1]
    searchResult = movieRentingSystem.search(2);
    cout << "Search(2): ";
    for (int shop : searchResult) cout << shop << " ";
    cout << endl;

    return 0;
}