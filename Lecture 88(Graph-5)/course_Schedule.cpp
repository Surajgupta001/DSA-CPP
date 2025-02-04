/*
Course Schedule - [Leetcode - 207(Medium)]
=============================================
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/ 

/*
APPROCH OF THESE PROBLEM

Step 1:
Create an Adjacency List and In-Degree Array
Create an adjacency list to represent the graph, where each index represents a course and the value at that index is a list of its prerequisites.
Create an in-degree array to keep track of the number of prerequisites for each course.

Step 2:
Initialize the Queue with Courses Having No Prerequisites
Initialize a queue with courses that have no prerequisites (in-degree 0).

Step 3:
Perform Topological Sorting
While the queue is not empty, dequeue a course and add it to the sorted list.
For each neighbor of the dequeued course, decrement its in-degree by 1.
If the in-degree of a neighbor becomes 0, add it to the queue.

Step 4:
Check for Cycles
If the size of the sorted list is equal to the number of courses, then there are no cycles in the graph and we can finish all courses.
Otherwise, there is a cycle in the graph and we cannot finish all courses.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourse, vector<vector<int>>& prerequisites){
    // Create an adjacency list and in-degree array
    vector<vector<int>> graph(numCourse);
    vector<int> inDegree(numCourse, 0);
    for (int i = 0; i < prerequisites.size(); i++){
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        inDegree[prerequisites[i][1]]++;
    }
    // Create a queue to store nodes with in-degree 0
    //                      OR
    // Initialize the queue with courses having no prerequisites
    queue<int> q;
    for (int i = 0; i < numCourse; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    // Perform Topological BFS 
    int sortedCourse = 0;
    while (!q.empty()){
        int course = q.front();
        q.pop();
        sortedCourse++;
        
        // For each neighbor of the dequeue course, decrement its in-degree by 1
        for(auto neighbor : graph[course]){
            inDegree[neighbor]--;
            // If the in-degree of the neighbor becomes 0, add it to the queue
            if (inDegree[neighbor] == 0) q.push(neighbor);
        }
    }
    // If the number of sorted courses is equal to the total number of courses, return true
    return sortedCourse == numCourse;
}

int main(){
    int numCourse = 2;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    cout << boolalpha << canFinish(numCourse, prerequisites) << endl;
    return 0;
}