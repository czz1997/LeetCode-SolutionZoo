class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        res = [[]]
        if len(nums) == 1:
            return [[],[nums[0]]]
        
        def backtracking(sub, start):
            if start >= len(nums):
                return
            else:
                for i in range(start, len(nums)):
                    sub.append(nums[i])
                    res.append(sub[:])
                    backtracking(sub, i + 1)
                    sub.pop()
        
        
        backtracking([], 0)
        return res 
