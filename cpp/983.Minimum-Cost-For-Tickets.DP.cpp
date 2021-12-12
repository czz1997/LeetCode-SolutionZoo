// 70% faster
// O(n), O(n)

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size());
        dp[days.size()-1] = min(costs[0], min(costs[1], costs[2]));
        for(int i{(int)days.size() - 2}; i >= 0; i--){
            // 1 day
            dp[i] = costs[0] + dp[i+1];
            // 7 day
            int j{};
            for(j=i+1; j<days.size(); j++){
                if(days[j] - days[i] >= 7)
                    break;
            }
            if(j<days.size()){
                dp[i] = min(dp[i], costs[1] + dp[j]);
            }
            else{
                dp[i] = min(dp[i], costs[1]);
            }
            // 30 day
            for(;j<days.size();j++){
                if(days[j] - days[i] >= 30)
                    break;
            }
            if(j<days.size()){
                dp[i] = min(dp[i], costs[2] + dp[j]);
            }
            else{
                dp[i] = min(dp[i], costs[2]);
            }
        }
        return dp[0];
    }
};
