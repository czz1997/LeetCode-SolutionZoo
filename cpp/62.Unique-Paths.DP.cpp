// 100% faster
// O(m+n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int table[m][n];
        table[m-1][n-1] = 1;  // I don't think it should be counted as a path though
        for(int i{n-2}; i>=0; i--){
            table[m-1][i] = 1;
        }
        for(int i{m-2}; i>=0; i--){
            table[i][n-1] = 1;
        }
        for(int i{m-2}; i>=0; i--){
            for(int j{n-2}; j>=0; j--){
                table[i][j] = table[i][j+1] + table[i+1][j];
            }
        }
        return table[0][0];
    }
};
