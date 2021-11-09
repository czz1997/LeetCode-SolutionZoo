class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        return Math.max(robHelp(Arrays.copyOfRange(nums, 0, nums.length - 1)), robHelp(Arrays.copyOfRange(nums, 1, nums.length)));
    }
    
    private int robHelp(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; ++i) {
            dp[i] = Math.max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.length - 1];
    }
}
// time complexity : faster 100% O(n)
// space complexity : faster 41.78% O(n)

// implement scolling array to optimize the space complexity
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        return Math.max(robHelp(Arrays.copyOfRange(nums, 0, nums.length - 1)), robHelp(Arrays.copyOfRange(nums, 1, nums.length)));
    }
    
    private int robHelp(int[] nums) {
        int pre = 0, curr = 0, temp;
        for (int i = 0; i < nums.length; ++i) {
            temp = curr;
            curr = Math.max(pre + nums[i], curr);
            pre = temp;
        }
        return curr;
    }
}
// time complexity : faster 100% O(n)
// space complexity : faster 91.92% O(1)
