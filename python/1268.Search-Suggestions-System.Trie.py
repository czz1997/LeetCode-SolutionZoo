# 5% faster
# O(M), O(n)
# M is total number of characters in products, n is the number of nodes in the trie (n <= M)

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        root = TrieNode()
        for product in products:
            node = root
            for c in product:
                if node.links[ord(c) - ord('a')] is None:
                    node.links[ord(c) - ord('a')] = TrieNode()
                node = node.links[ord(c) - ord('a')]
            node.is_end = True
        
        out = []
        node = root
        cur = ""
        for c in searchWord:
            cur += c
            res = []
            node = node.links[ord(c) - ord('a')] if node is not None else None
            if node is None:
                out.append(res)
                continue
            self.dfs(node, res, cur)
            out.append(res)
                
        return out
            
    def dfs(self, node, res, cur):
        if node.is_end:
            res.append(cur)
        i = 0
        while len(res) < 3 and i < len(node.links):
            if node.links[i] is not None:
                self.dfs(node.links[i], res, cur + chr(ord('a') + i))
            i += 1
        

class TrieNode:
    def __init__(self):
        self.links = [None for i in range(26)]
        self.is_end = False
        
