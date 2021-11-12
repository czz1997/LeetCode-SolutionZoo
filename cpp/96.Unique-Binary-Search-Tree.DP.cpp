// 100% faster
// Time complexity O(n^2), space complexity O(n)

class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        if(n >= 2){
            dp[2] = 2;
            for(int i{3}; i<=n; i++){
                dp[i] = 0;
                for(int c{}; c < i; c++){
                    dp[i] += dp[c] * dp[i-c-1];
                }
            }
        }
        return dp[n];
    }
};
