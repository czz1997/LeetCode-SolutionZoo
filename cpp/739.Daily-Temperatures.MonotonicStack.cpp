// 97% faster
// Time complexity O(n), space complexity O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> s{0};
        vector<int> ans(temperatures.size(), 0);
        for(int i{1}; i<temperatures.size(); i++){
            if(temperatures[i] > temperatures[s.back()])
                while(!s.empty() && temperatures[i] > temperatures[s.back()]){
                    ans[s.back()] = i - s.back();
                    s.pop_back();
                }
            s.push_back(i);
        }
        return ans;
    }
};
