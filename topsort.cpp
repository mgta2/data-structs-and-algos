// Topological Sort with DFS

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Graph {
public:
    vector<vector<int>> graph;
    int n;
    vector<int> markings, output;

Graph(vector<vector<int>> input) : graph(input), n(graph.size()) {
    output = vector<int>(0);
    markings = vector<int>(n);
    for (int i = 0; i < n; i++) markings[i] = 0;
}

vector<int> topSort() {
    for (int i = 0; i < n; i++) {
        if (markings[i]==0) dfs(i);
    }
    reverse(output.begin(),output.end());
    return output;
}

void dfs(int i) {
    if (markings[i]==2) return;
    if (markings[i]==1) throw invalid_argument("The graph is not acyclic - no topological sorting exists.");
    markings[i] = 1;
    for (int adjacent : graph[i]) {
        dfs(adjacent);
    }
    markings[i] = 2;
    output.push_back(i);
}

};

int main() {
    vector<int> n0,n1,n2,n3,n4;
    n0 = {1};
    n1 = {3};
    n2 = {3};
    n3 = {4};
    n4 = {};
    Graph graph({n0,n1,n2,n3,n4});
    auto res = graph.topSort();
    for (int x : res) cout << x << " ";
    cout << endl;
    // Output: 2 0 1 3 4

    vector<int> m0,m1,m2;
    m0 = {1};
    m1 = {2};
    m2 = {0};
    Graph m_graph({m0,m1,m2});
    try {
        auto m_res = m_graph.topSort();
    }
    catch (const invalid_argument& e) {
        cout << "Failure - graph contains a cycle." << endl;
    }
    // Output: Failure - graph contains a cycle.

    vector<int> a0,a1,a2,a3,a4,a5;
    a0 = {1,2};
    a1 = {3,4};
    a2 = {3,4};
    a3 = {5};
    a4 = {5};
    a5 = {};
    Graph a_graph({a0,a1,a2,a3,a4,a5});
    auto a_res = a_graph.topSort();
    for (int x : a_res) cout << x << " ";
    cout << endl;
    // Output: 0 2 1 4 3 5
    
    return 0;
}