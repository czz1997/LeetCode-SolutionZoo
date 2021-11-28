// 78 % faster
// Time complexity O(n), space complexity O(1)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> m(26, -1);
        // Check the last occurance of every character
        for(int i{}; i<s.length(); i++){
            m[s[i]-'a'] = i;
        }
        int checkpoint{m[s[0]-'a']};
        int lastCheckpoint{-1};
        vector<int> res;
        // Partition labels
        for(int i{}; i < s.length(); i++){
            if(i == checkpoint){
                res.push_back(i - lastCheckpoint);
                if(i+1<s.length()){
                    lastCheckpoint = checkpoint;
                    checkpoint = m[s[i+1]-'a'];
                }
            }
            else{
                checkpoint = max(checkpoint, m[(int)(s[i]-'a')]);
            }
        }
        return res;
    }
};
