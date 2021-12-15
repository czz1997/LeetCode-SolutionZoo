# 87% faster
# O(n), O(n)

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        # construct frequency dictionary
        freq = {}
        for num in arr:
            freq[num] = freq.get(num, 0) + 1
        res = len(freq.keys())
        
        # count the number of each frequency
        freq_arr = [0 for i in range(len(arr) + 1)]
        for num, freq in freq.items():
            freq_arr[freq] += 1
        
        # remove integers starting from the least frequent ones
        for i in range(1, len(freq_arr)):
            if k - i * freq_arr[i] > 0:
                k -= i * freq_arr[i]
                res -= freq_arr[i]
            elif k - i * freq_arr[i] == 0:
                return res - freq_arr[i]
            else:
                return res - int(k / i)
