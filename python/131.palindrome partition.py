class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPalindrome(string):
            l, r = 0, len(string) - 1
            while l <= r:
                if string[l] != string[r]:
                    return False
                l += 1
                r -= 1
            return True
        
        res = []
        if len(s) == 1:
            return [[s[0]]]
        
        def backtracking(sub, curr, length):
            if length == len(s):
                res.append(sub[:])
                return
            else:
                for i in range(len(curr)):
                    if isPalindrome(curr[0:i + 1]):
                        sub.append(curr[0:i + 1])
                        backtracking(sub, curr[i + 1:], length + len(curr[0:i + 1]))
                        sub.pop()     

        backtracking([], s, 0)
        return res
        
        #O(n*2^n) cost n to check whether it is a palindrome
