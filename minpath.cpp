// BFS to find path of shortest distance in an unweighted graph.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

pair<vector<int>,int> shortestDist(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size(), node = end, current;
    vector<int> parents(n), path;
    queue<int> q;
    q.push(start);
    unordered_set<int> seen;
    seen.insert(start);
    
    while (!q.empty()) {
        current = q.front();
        if (current==end) break;
        q.pop();
        for (int adjacent : graph[current]) {
            if (seen.find(adjacent)==seen.end()) {
                seen.insert(adjacent);
                q.push(adjacent);
                parents[adjacent] = current;
            }
        }
    }
    
    while (node!=start) {
        path.push_back(node);
        node = parents[node];
    }
    path.push_back(start);
    
    reverse(path.begin(),path.end());
    
    return {path, path.size()-1};
}

// Testing

int main()
{
    vector<vector<int>> graph;
    vector<int> n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
    n0 = {1};
    n1 = {0,2,10};
    n2 = {1,3,9};
    n3 = {2,4,9};
    n4 = {3,5,6,8};
    n5 = {4,6};
    n6 = {4,5,7};
    n7 = {6,8};
    n8 = {4,7,9,10};
    n9 = {2,3,8,10};
    n10 = {1,8,9};
    graph = {n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10};
    
    auto [path1,dist1] = shortestDist(graph, 1, 8);
    cout << "Path: ";
    for (int i = 0; i < path1.size()-1; i++) {
        cout << path1[i] << " -> ";
    }
    cout << path1[path1.size()-1] << " (distance = " << dist1 << ")" << endl;
    // Path: 1 -> 10 -> 8 (distance = 2)
    
    auto [path2,dist2] = shortestDist(graph, 0, 5);
    cout << "Path: ";
    for (int i = 0; i < path2.size()-1; i++) {
        cout << path2[i] << " -> ";
    }
    cout << path2[path2.size()-1] << " (distance = " << dist2 << ")" << endl;
    // Path: 0 -> 1 -> 2 -> 3 -> 4 -> 5 (distance = 5)
    
    auto [path3,dist3] = shortestDist(graph, 6, 1);
    cout << "Path: ";
    for (int i = 0; i < path3.size()-1; i++) {
        cout << path3[i] << " -> ";
    }
    cout << path3[path3.size()-1] << " (distance = " << dist3 << ")" << endl;
    // Path: 6 -> 4 -> 3 -> 2 -> 1 (distance = 4)

    return 0;
}