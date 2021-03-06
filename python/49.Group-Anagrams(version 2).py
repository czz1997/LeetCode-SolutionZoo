#faster than 57.05% (not reliable)
#Time: O(n*m) where n is the length of the input string array, m is the length of the longest word of input array.


class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        countToStr = {}
        
        for s in strs:
            count = [0]*26
            
            for c in s:
                count[ord(c) - ord('a')] += 1
            
            if tuple(count) in countToStr:
                countToStr[tuple(count)].append(s)
            else:
                countToStr[tuple(count)] = [s]
            
        return countToStr.values()
        
