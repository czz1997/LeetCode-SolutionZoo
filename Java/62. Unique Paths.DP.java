class Solution {
    public int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // dp[0][0]
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                // dp[i][0] or dp[0][j]
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
}
// time complexity : faster 100% O(m * n)
// space complexity : faster 75.15% O(m * n)
