# 91% faster
# O(n^2), O(n)

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        dp = [matrix[-1][i] for i in range(len(matrix[0]))]
        for i in range(len(matrix) - 2, -1, -1):
            diag_left = dp[0]
            dp[0] = matrix[i][0] + min(dp[0], dp[1])
            for j in range(1, len(matrix[0]) - 1):
                temp = dp[j]
                dp[j] = matrix[i][j] + min(diag_left, min(dp[j], dp[j+1]))
                diag_left = temp
            dp[-1] = matrix[i][-1] + min(diag_left, dp[-1])
        return min(dp)
