class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        l, r = 0, len(matrix)*len(matrix[0]) - 1
        cols = len(matrix[0])
        
        while l <= r:
            mid = (l + r)//2
            if matrix[mid // cols][mid % cols] == target:
                return True
            elif matrix[mid // cols][mid % cols] > target:
                r = mid - 1
            elif matrix[mid // cols][mid % cols] < target:
                l = mid + 1
        
        return False
    
    
#23 ms, 80.54%
#O(log(m*n))
