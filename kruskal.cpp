// Kruskal's Algorithm Implementation.

#include <vector>
#include <iostream>
#include <algorithm>

class UnionFind {
public:
    std::vector<int> classes;
    std::vector<int> rank;
    UnionFind(int n) {
        classes = std::vector<int>(n);
        for (int i = 0; i < n; i++) classes[i] = i;
        rank = std::vector<int>(n);
    }
    int find(int i) {
        if (classes[i] != i) {
            classes[i] = find(classes[i]);
        }
        return classes[i];
    }
    bool join(int i, int j) {
        int ec1 = find(i);
        int ec2 = find(j);
        if (ec1 == ec2) return false;
        if (rank[ec1] > rank[ec2]) classes[ec2] = ec1;
        else if (rank[ec2] > rank[ec1]) classes[ec1] = ec2;
        else {
            classes[ec1] = ec2;
            rank[ec2] += 1;
        }
        return true;
    }
};

using namespace std;

pair<vector<pair<int,int>>,int> findMinSpanningTree(vector<vector<pair<int,int>>>& graph) {
    vector<pair<int,int>> result;
    int n = graph.size();
    // Input graph is adjacency list with weights attached.
    // Want to sort by weights so convert this into a nicer format...
    vector<pair<int,pair<int,int>>> edges;
    for (int i = 0; i < n; i++) {
        for (auto [end_node, weight] : graph[i]) {
            edges.push_back({weight, {i, end_node}});
        }
    }
    sort(edges.begin(),edges.end());
    UnionFind uf(n);
    int edgesUsed = 0, minimal_weight = 0;
    for (int i = 0; i < edges.size() && edgesUsed < n-1; i++) {
        int start_node = edges[i].second.first;
        int end_node = edges[i].second.second;
        int weight = edges[i].first;
        if (uf.join(start_node,end_node)) {
            result.push_back({start_node,end_node});
            minimal_weight += weight;
            edgesUsed++;
        }
    }
    return {result,minimal_weight};
}

// Mini test.

int main() {
    vector<vector<pair<int,int>>> graph;
    vector<pair<int,int>> n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
    n0 = {{1,34}};
    n1 = {{0,34},{2,45},{10,15}};
    n2 = {{1,45},{3,33},{9,23}};
    n3 = {{2,33},{4,77},{9,11}};
    n4 = {{3,77},{5,24},{6,23},{8,89}};
    n5 = {{4,24},{6,12}};
    n6 = {{4,23},{5,12},{7,5}};
    n7 = {{6,5},{8,48}};
    n8 = {{4,89},{7,48},{9,12},{10,55}};
    n9 = {{2,23},{3,11},{8,12},{10,7}};
    n10 = {{1,15},{8,55},{9,7}};
    graph = {n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10};
    auto x = findMinSpanningTree(graph);
    for (auto [a,b] : x.first) {
        cout << a << "->" << b << endl;
    }
    cout << "Weight: " << x.second << endl;
    // Output gives a spanning tree of weight 190.
    return 0;
}