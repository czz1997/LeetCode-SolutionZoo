// 89% faster
// Time complexity O(n^2), space complexity O(1)

class Solution {
public:
    int countSubstrings(string s) {
        int res{(int)s.length()};  // each character is a palindromic substring
        int i, j, k;
        for(i = 0; i<s.length(); i++){
            // expand right
            for(j = i+1; j < s.length() && s[j] == s[i]; j++){
                res++;
            }
            j--;
            // expand both sides
            for(k = 1; i - k >= 0 && j + k < s.length() && s[i-k] == s[j+k]; k++){
                res++;
            }
        }
        
        return res;
    }
};
