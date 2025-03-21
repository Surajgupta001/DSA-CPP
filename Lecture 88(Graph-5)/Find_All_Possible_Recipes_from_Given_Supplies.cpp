/*
Find All Possible Recipes from Given Supplies - [Leetcode - 2115(Medium)]
===========================================================================
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

 

Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".

Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".

Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
 

Constraints:

n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.
*/ 

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

/*
===================================== Brute Force ====================================
vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    int n = recipes.size();
    vector<string> result;
    unordered_set<string> st(begin(supplies), end(supplies));
    vector<bool> cooked(n, false);
    
    int count = n;
    while(count--) {
        for(int j = 0; j < n; j++) {
            if(cooked[j]) {
                continue;
            }
            bool banpaega = true;
            for(int k = 0; k < ingredients[j].size(); k++) {
                if(!st.count(ingredients[j][k])) {
                    banpaega = false;
                    break;
                }
            }
            if(banpaega) {
                st.insert(recipes[j]);
                result.push_back(recipes[j]);
                cooked[j] = true;
            }
        }
    }
    return result;
}
*/ 

// Topological Sorting
vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    int n = recipes.size();
    unordered_set<string> st(begin(supplies), end(supplies));

    //adj
    unordered_map<string, vector<int>> adj; //ing ---> recipe


    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++) {
        for(string& ing : ingredients[i]) {
            if(!st.count(ing)) {
                adj[ing].push_back(i);
                indegree[i]++;
            }
        }
    }

    queue<int> que;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            que.push(i);
        }
    }

    vector<string> result;
    while(!que.empty()) {
        int i = que.front();
        que.pop();
        string recipe = recipes[i];
        result.push_back(recipe);

        for(int &idx : adj[recipe]) {
            indegree[idx]--;
            if(indegree[idx] == 0) {
                que.push(idx);
            }
        }
    }
    return result;
}

int main() {
    // Example 1
    vector<string> recipes1 = {"bread"};
    vector<vector<string>> ingredients1 = {{"yeast", "flour"}};
    vector<string> supplies1 = {"yeast", "flour", "corn"};

    vector<string> result1 = findAllRecipes(recipes1, ingredients1, supplies1);
    cout << "Example 1 Result: ";
    for (const auto& recipe : result1) {
        cout << recipe << " ";
    }
    cout << endl;

    // Example 2
    vector<string> recipes2 = {"bread", "sandwich"};
    vector<vector<string>> ingredients2 = {{"yeast", "flour"}, {"bread", "meat"}};
    vector<string> supplies2 = {"yeast", "flour", "meat"};

    vector<string> result2 = findAllRecipes(recipes2, ingredients2, supplies2);
    cout << "Example 2 Result: ";
    for (const auto& recipe : result2) {
        cout << recipe << " ";
    }
    cout << endl;

    // Example 3
    vector<string> recipes3 = {"bread", "sandwich", "burger"};
    vector<vector<string>> ingredients3 = {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}};
    vector<string> supplies3 = {"yeast", "flour", "meat"};

    vector<string> result3 = findAllRecipes(recipes3, ingredients3, supplies3);
    cout << "Example 3 Result: ";
    for (const auto& recipe : result3) {
        cout << recipe << " ";
    }
    cout << endl;

    return 0;
}