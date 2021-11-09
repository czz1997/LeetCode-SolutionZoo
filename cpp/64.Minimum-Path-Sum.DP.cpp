// 98% faster
// O(m*n) time, O(m*n) space

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int table[grid.size()][grid[0].size()];
        table[grid.size() - 1][grid[0].size() - 1] = grid[grid.size() - 1][grid[0].size() - 1];
        for(int i{int(grid.size()) - 2}; i>=0; i--){
            table[i][grid[0].size() - 1] = grid[i][grid[0].size() - 1] + table[i + 1][grid[0].size() - 1];
        }
        for(int i{int(grid[0].size()) - 2};i>=0;i--){
            table[grid.size() - 1][i] = grid[grid.size() - 1][i] + table[grid.size() - 1][i+1];
        }
        for(int i{int(grid.size()) - 2}; i>=0; i--){
            for(int j{int(grid[0].size()) - 2}; j>=0; j--){
                table[i][j] = grid[i][j] + min(table[i][j+1], table[i+1][j]);
            }
        }
        return table[0][0];
    }
};
