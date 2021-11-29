class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        if m == 1 or n == 1:
            return 1
        
        dp = [n*[0] for i in range(m)]
        
        for j in range(1, n):
            dp[0][j] = 1        
        for i in range(1, m):
            dp[i][0] = 1
        
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        return dp[-1][-1]
    
        #time complicity O(m*n)
