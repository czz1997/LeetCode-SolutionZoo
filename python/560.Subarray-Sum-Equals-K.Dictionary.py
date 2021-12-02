class Solution:
    # 71% faster
    # Time complexity O(n), space complexity O(n)
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        d = {0: 1}
        sum = 0
        for num in nums:
            sum += num
            res += d.get(sum-k, 0)
            d[sum] = d.get(sum, 0) + 1
        return res
    
    # time limit exceeded
    # Time complexity O(n^2), space complexity O(1)
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        for i in range(len(nums)):
            s = 0
            for j in range(i, len(nums)):
                s += nums[j]
                if s == k:
                    res += 1
        return res
