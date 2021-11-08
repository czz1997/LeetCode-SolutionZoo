// 77% faster

class Solution {
public:
    string longestPalindrome(string s) {
        int p, q;
        int maxL{1};
        int bestp{-1}, bestq{1};
        for(int idx{}; idx < s.length(); idx++){
            p = idx - 1;
            q = idx + 1;
            while(p >= 0 && s[p] == s[idx]){
                p --;
            }
            while(q < s.length() && s[q] == s[idx]){
                q++;
            }
            while(p>=0 && q < s.length() && s[p] == s[q]){
                p--;
                q ++;
            }
            if(q - p - 1 > maxL){
                bestp = p;
                bestq = q;
                maxL = q - p - 1;
            }
        }
        return s.substr(bestp + 1, bestq - bestp - 1);
    }
};