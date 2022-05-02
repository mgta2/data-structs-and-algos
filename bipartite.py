# Bipartite Graph Checker

"""
Program to check if given undirected graph is bipartite/2-colourable.
Graph may be disconnected, but has no self edges etc (all the standard rules).
Input 'graph' is an adjacency list.
"""

def isBipartite(graph) -> bool:
    
    n = len(graph)
    colouring = [0]*n # uncoloured = 0, red = +1, blue = -1
    
    # Breadth First Search
    seen = set()
    parity = 1
    
    for i in range(n):
        if i in seen:
            continue
        seen.add(i)
        queue = [i]
        while queue:
            parity *= -1
            next_queue = []
            for current in queue:
                # Colour the node.
                colouring[current] = parity
                # Check this doesn't break anything AND add unvisited adjacents into queue.
                for adjacent in graph[current]:
                    if colouring[adjacent] == parity:
                        # An adjacent node has the same colour - contradiction.
                        return False
                    if adjacent not in seen:
                        next_queue.append(adjacent)
                        seen.add(adjacent)
            queue = next_queue
    # If code reaches this point then we have a valid 2-colouring.
    return True