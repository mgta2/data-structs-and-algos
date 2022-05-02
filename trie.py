# Trie

"""
My solution to https://leetcode.com/problems/implement-trie-prefix-tree/

"""

class TrieNode:
    def __init__(self, char = ""):
        self.char = char
        self.children = {}
        self.is_end = False

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        # O(len(word)) time and space complexity.
        node = self.root
        for char in word:
            if char in node.children:
                node = node.children[char]
            else:
                next_node = TrieNode(char)
                node.children[char] = next_node
                node = next_node
        node.is_end = True

    def search(self, word: str) -> bool:
        # O(len(word)) time complexity, O(1) space complexity.
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end

    def startsWith(self, prefix: str) -> bool:
        # O(len(word)) time complexity, O(1) space complexity.
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True