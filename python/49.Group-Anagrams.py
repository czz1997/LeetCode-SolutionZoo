# 84% faster

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        res = []
        for i in range(len(strs)):
            cur = tuple(sorted(strs[i]))
            if cur in d.keys():
                res[d[cur]].append(strs[i])
            else:
                d[cur] = len(res)
                res.append([strs[i]])
        return res
