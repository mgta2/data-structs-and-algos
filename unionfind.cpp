// Union Find

/*
This data structure is a clean way of tracking equivalence classes of integers in the range [0,n].
It is useful in graph problems for tracking which nodes are in the same connected component, for example.
More description of how the class works is in the Python version.
https://en.wikipedia.org/wiki/Disjoint-set_data_structure
*/

#include <vector>

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