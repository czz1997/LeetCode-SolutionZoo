# 99% faster
# O(mn), O(n)

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        dp = [int(c) for c in matrix[0]]
        maxL = max(dp)
            
        for i in range(1, m):
            dp[0] = int(matrix[i][0])
            maxL = max(maxL, dp[0])
            for j in range(1, n):
                if matrix[i][j] == "1":
                    l = min(dp[j], dp[j-1])
                    if l > 0:
                        if matrix[i-l][j-l] == "1":
                            dp[j] = l + 1
                        else:
                            dp[j] = l
                    else:
                        dp[j] = 1
                    maxL = max(dp[j], maxL)
                else:
                    dp[j] = 0
        return maxL ** 2
      
