/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
        return {0};
    }

    vector<vector<int>> graph(n);
    vector<int> degree(n, 0);

    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    queue<int> leaves;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) {
            leaves.push(i);
        }
    }

    while (n > 2) {
        int leavesCount = leaves.size();
        n -= leavesCount;

        for (int i = 0; i < leavesCount; ++i) {
            int leaf = leaves.front();
            leaves.pop();

            for (int neighbor : graph[leaf]) {
                degree[neighbor]--;
                if (degree[neighbor] == 1) {
                    leaves.push(neighbor);
                }
            }
        }
    }

    vector<int> result;
    while (!leaves.empty()) {
        result.push_back(leaves.front());
        leaves.pop();
    }

    return result;
}

int main() {
    int n1 = 4;
    vector<vector<int>> edges1 = {{1, 0}, {1, 2}, {1, 3}};
    vector<int> result1 = findMinHeightTrees(n1, edges1);
    cout << "Output for Example 1: ";
    for (int node : result1) {
        cout << node << " ";
    }
    cout << endl;

    int n2 = 6;
    vector<vector<int>> edges2 = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    vector<int> result2 = findMinHeightTrees(n2, edges2);
    cout << "Output for Example 2: ";
    for (int node : result2) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
