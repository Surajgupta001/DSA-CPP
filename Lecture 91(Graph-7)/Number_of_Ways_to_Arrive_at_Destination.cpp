/*
Number of Ways to Arrive at Destination - [Leetcode - 1976(Medium)]
==================================================================
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.


Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.


Constraints:

1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <climits>
#define ll long long int
// #define pp pair<int, int>
using namespace std;

/*
vector<list<pair<int, int>>>graph; // <int,int> ---> <vertex, weight> -- weighted graph
void add_edge(int u, int v, int wt, bool bi_dir = true){
    graph[u].push_back({v, wt});
    if (bi_dir) graph[v].push_back({u, wt});
}

unordered_map<int, int> dijkstra(int src, int n){ // O(VlogV + ElogV)
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>q; // {wt, node}
    unordered_set<int> visited;
    vector<int> via(n + 1);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[i] = INT_MAX; // O(V)
    q.push({0, src});
    mp[src] = 0;

    while (not q.empty()){ // O((V+E)logV)
        pair<int, int> curr = q.top();
        if (visited.count(curr.second)){
            q.pop();
            continue;
        }
        visited.insert(curr.second);
        q.pop();
        for (auto neighbour : graph[curr.second]){
            if (not visited.count(neighbour.first) and
                mp[neighbour.first] > mp[curr.second] + neighbour.second){
                q.push({mp[curr.second] + neighbour.second, neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = mp[curr.second] + neighbour.second;
            }
        }
    }
    return mp;
}

int countPaths(int n, vector<vector<int>> &roads){
    vector<vector<pair<int, int>>> graph(n);
    for (auto &road : roads){
        graph[road[0]].push_back({road[1], road[2]});
        graph[road[1]].push_back({road[0], road[2]});
    }

    vector<int> dist(n, INT_MAX);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
    pq.push({0, 0});

    while (!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto &neighbor : graph[node]){
            if (d + neighbor.second == dist[neighbor.first]){
                ways[neighbor.first] = (ways[neighbor.first] + ways[node]) % (int)(1e9 + 7);
            }
            else if (d + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = d + neighbor.second;
                ways[neighbor.first] = ways[node];
                pq.push({d + neighbor.second, neighbor.first});
            }
        }
    }
    return ways[n - 1];
}
*/

typedef pair<long long, int> P;
const int M = 1e9 + 7;
int countPaths(int n, vector<vector<int>> &roads){

    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto &road : roads){
        int u = road[0];
        int v = road[1];
        int time = road[2];
        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<long long> result(n, LLONG_MAX);
    vector<int> pathCount(n, 0);

    result[0] = 0;
    pathCount[0] = 1;
    pq.push({0, 0});

    while (!pq.empty()){
        long long currTime = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        // if (currTime > result[currNode]) continue;

        for (auto &vec : adj[currNode]){
            int adjNode = vec.first;
            int roadTime = vec.second;

            if (currTime + roadTime < result[adjNode]){
                result[adjNode] = currTime + roadTime;
                pathCount[adjNode] = pathCount[currNode];
                pq.push({result[adjNode], adjNode});
            }
            else if (currTime + roadTime == result[adjNode]){
                pathCount[adjNode] = (pathCount[adjNode] + pathCount[currNode]) % M;
            }
        }
    }
    return pathCount[n - 1];
}

int main() {
    // Example 1
    int n1 = 7;
    vector<vector<int>> roads1 = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    cout << "Example 1: Number of ways to arrive at destination = " << countPaths(n1, roads1) << endl;

    // Example 2
    int n2 = 2;
    vector<vector<int>> roads2 = {{1,0,10}};
    cout << "Example 2: Number of ways to arrive at destination = " << countPaths(n2, roads2) << endl;

    return 0;
}