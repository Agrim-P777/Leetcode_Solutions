/*
Leetcode_210
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> inEdges(numCourses,0);
        vector<int> res;

        for(const vector<int> &pre: prerequisites){
           graph[pre[1]].push_back(pre[0]);
           inEdges[pre[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
           if(inEdges[i]==0) q.push(i);
        }

        while(!q.empty()){
             int course = q.front();
             res.push_back(course);
             q.pop();

             for(int c: graph[course]){
                 inEdges[c]--;
                 if(inEdges[c]==0) q.push(c);
             }
        }
        if(res.size() == numCourses) return res;
        else {
             res.clear();
             return res;
        }

        }    
};