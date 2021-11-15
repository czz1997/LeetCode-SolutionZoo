// 97% faster
// Time complexity O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m{}, maxVal{prices[prices.size() - 1]};
        for(int i{int(prices.size()) - 2}; i>=0; i--){
            maxVal = max(prices[i], maxVal);
            m = max(maxVal - prices[i], m);
        }
        return m;
    }
};
