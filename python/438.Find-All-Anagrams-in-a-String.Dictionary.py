# 75% faster
# Time complexity O(n), space complexity O(1)

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []
        
        d = {}
        for c in p:
            d[c] = d.get(c, 0) + 1
            
        res = []
        count = 0
        for i in range(len(p)):
            if d.get(s[i], None) is not None:
                d[s[i]] -= 1
                if d[s[i]] >= 0:
                    count += 1
        if count == len(p):
            res.append(0)
                    
        for i in range(1, len(s) - len(p) + 1):
            if d.get(s[i-1], None) is not None:
                d[s[i-1]] += 1
                if d[s[i-1]] > 0:
                    count -= 1
                    
            if d.get(s[i+len(p)-1], None) is not None:
                d[s[i+len(p)-1]] -= 1
                if d[s[i+len(p)-1]] >= 0:
                    count += 1
            
            if count == len(p):
                res.append(i)
        
        return res
