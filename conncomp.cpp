// Given an undirected graph adjacency list, find the connected components.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

vector<vector<int>> findConnComp (vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> held;
    unordered_set<int> seen;
    int n = graph.size();
    
    for (int i = 0; i < n; i++) {
        if (seen.find(i)!=seen.end()) continue;
        seen.insert(i);
        // Breadth First Search
        held.clear();
        queue<int> q;
        int current;
        q.push(i);
        while (!q.empty()) {
            current = q.front();
            held.push_back(current);
            q.pop();
            for (int adjacent : graph[current]) {
                if (seen.find(adjacent)==seen.end()) {
                    seen.insert(adjacent);
                    q.push(adjacent);
                }
            }
        }
        result.push_back(held);
    }
    return result;
}

// Mini Test

int main()
{
    vector<int> n0,n1,n2,n3,n4,n5,n6,n7;
    n0 = {1};
    n1 = {0,2,3};
    n2 = {1,3};
    n3 = {1,2};
    n4 = {5};
    n5 = {4,6};
    n6 = {5};
    n7 = {};
    vector<vector<int>> graph = {n0,n1,n2,n3,n4,n5,n6,n7};
    auto result = findConnComp(graph);
    for (auto x : result) {
        for (auto node : x) {
            cout << node << " ";
        }
        cout << endl;
    }
    // Output: 0 1 2 3, 4 5 6, 7
    return 0;
}