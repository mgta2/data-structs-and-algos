# Union Find

"""
This data structure is a clean way of tracking equivalence classes of integers in the range [0,n].
It is useful in graph problems for tracking which nodes are in the same connected component, for example.
https://en.wikipedia.org/wiki/Disjoint-set_data_structure
"""

class UnionFind:
    def __init__(self, n: int):
        # Fixed points are representatives of their equivalence class.
        self.classes = [i for i in range(0, n)]
        # Rank tracks approximate size of equivalence class corresponding to given representative.
        self.rank = [0]*n
    
    def find(self, i: int):
        # Get representative element; fixed point within cycle.
        if self.classes[i] != i:
            self.classes[i] = self.find(self.classes[i])
        return self.classes[i]
    
    def join(self, i: int, j: int) -> bool:
        # Update representative; choose lower rank so less cost.
        # We don't need to update every member of the combined class to reflect new representative.
        # Just make sure that all paths lead to the new representative. This is quicker (see Wikipedia above).
        e_class1 = self.find(i)
        e_class2 = self.find(j)
        if e_class1 == e_class2:
            # Failed to join as they're already in the same equiv class.
            return False
        if self.rank[e_class1] > self.rank[e_class2]:
            self.classes[e_class2] = e_class1
        elif self.rank[e_class1] < self.rank[e_class2]:
            self.classes[e_class1] = e_class2
        else:
            # Equal rank so just choose one at random.
            self.classes[e_class1] = e_class2
            # e_class2 is chosen so increase its rank to reflect this.
            self.rank[e_class2] += 1
        return True