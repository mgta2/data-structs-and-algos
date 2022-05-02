// Bipartite Graph Checker
/*
Program to check if given undirected graph is bipartite/2-colourable.
Graph may be disconnected, but has no self edges etc (all the standard rules).
Input 'graph' is an adjacency list.
*/

#include <vector>
#include <unordered_set>

bool isBipartite(std::vector<std::vector<int>>& graph) {

    int n = graph.size();
    int parity = 1;
    std::vector<int> colouring = std::vector<int>(n);
    std::unordered_set<int> seen;
    std::vector<int> queue;
    std::vector<int> next_queue;

    for (int i = 0; i < n; i++) {

        if (seen.find(i) != seen.end()) continue;
        seen.insert(i);
        queue.clear();
        queue.push_back(i);

        while (!queue.empty()) {

            parity *= -1;
            next_queue.clear();

            for (int current : queue) {

                colouring[current] = parity;
                for (int adjacent : graph[current]) {

                    if (colouring[adjacent] == parity) return false;
                    if (seen.find(adjacent) == seen.end()) {

                        next_queue.push_back(adjacent);
                        seen.insert(adjacent);

                    }

                }

            }

            queue = next_queue;

        }

    }

    return true;

}