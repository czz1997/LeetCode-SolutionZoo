class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        dp = (amount + 1) * [amount + 1]
        dp[0] = 0
        
        if amount == 0:
            return 0
        
        for i in range(len(coins)):
            for j in range(coins[i], amount + 1):
                dp[j] = min(dp[j], dp[j-coins[i]] + 1)
                
        
        return dp[amount] if dp[amount] != amount + 1 else -1
      
      #time complexity: O(amount*|coins|)
