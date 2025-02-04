/*
Course schedule  - [Leetcode - 210]
======================================
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
*/ 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourse, vector<vector<int>>& prerequisites){
    
    // Create graph and in-degree
    vector<vector<int>> graph(numCourse);
    vector<int> indegree(numCourse, 0);

    // Calculate in-degree
    for(auto prerequisite : prerequisites){
        graph[prerequisite[1]].push_back(prerequisite[0]);
        indegree[prerequisite[0]]++;
    }
    
    // Create the queue with nodes that have in-degree 0
    queue<int> q;
    for(int i=0; i<numCourse; i++) if(indegree[i] == 0) q.push(i);
    
    // Create topological sorting
    vector<int> topologicalOrder;
    while(!q.empty()){
        int course = q.front();
        q.pop();
        topologicalOrder.push_back(course);
        
        // Decrease in-degree of all neighbours
        for(auto neighbour : graph[course]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) q.push(neighbour);
        }
    }
    
    // Check if there is a cycle in the graph
    if(topologicalOrder.size() != numCourse) return {};
    return topologicalOrder;
}

int main(){
    
    int numCourses = 4;
    
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> result = findOrder(numCourses, prerequisites);
    
    if(result.empty()){
        cout<<"No valid order found."<<endl;
    }
    else{
        cout<<"Valid order: ";
        for(auto course : result) cout<<course<<" ";
        cout<<endl;
    }
    return 0;
}