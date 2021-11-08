# 64% faster

class Solution:
    def longestPalindrome(self, s: str) -> str:
        out, cur = "", ""
        for idx, c in enumerate(s):
            p = idx - 1
            q = idx + 1
            cur = c
            while p >= 0 and s[p] == c:
                p -= 1
            while q < len(s) and s[q] == c:
                q += 1
            while p >= 0 and q < len(s):
                if s[p] == s[q]:
                    p -= 1
                    q += 1
                else:
                    break
            cur = s[p+1: q]
            if len(cur) > len(out):
                out = cur
        return out
                
                