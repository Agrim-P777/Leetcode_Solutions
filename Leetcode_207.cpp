/*
Leetcode - 207
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> graph;
    vector<int> inDegree(numCourses, 0);
    
    for (const vector<int>& pre : prerequisites) {
        graph[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    int visitedCourses = 0;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        visitedCourses++;
        
        for (int neighbor : graph[course]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return visitedCourses == numCourses;
}

int main() {
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << canFinish(2, prerequisites1) << endl; // Output: 1 (True)
    
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << canFinish(2, prerequisites2) << endl; // Output: 0 (False)
    
    return 0;
}
