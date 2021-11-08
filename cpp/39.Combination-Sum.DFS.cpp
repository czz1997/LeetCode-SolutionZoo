// 93% faster

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, 0, res, cur, target);
        return res;
    }
    
    void dfs(vector<int>& candidates, int start, vector<vector<int>>& res, vector<int>& cur, int target){
        int maxFreq{target / candidates[start]};
        for(int i{}; i<=maxFreq; i++){
            if(i > 0){
                // add one candidate at a time
                cur.push_back(candidates[start]);
            }
            int nextTarget{target - i * candidates[start]};
            if(nextTarget == 0){
                // target will be 0 at next dfs node
                res.push_back(cur);
            }
            else if(nextTarget > candidates[start] && start + 1 < candidates.size()){
                // ensure that next index is valid, and next candidate will not exceed next target
                dfs(candidates, start + 1, res, cur, target - i * candidates[start]);
            }
        }
        cur.erase(cur.end() - maxFreq, cur.end());
    }
};