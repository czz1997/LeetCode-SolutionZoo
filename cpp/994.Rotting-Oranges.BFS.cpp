// 90% faster
// Time complexity O(m*n), space complexity O(m*n)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> q;
        int freshCount{};
        int m = grid.size();
        int n = grid[0].size();
        int mins{};
        int i{}, j{};
        // Push all rotten oranges into queue, count fresh oranges
        for(; i<m; i++){
            for(j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push(i * n + j);
                }
                else if(grid[i][j] == 1){
                    freshCount ++;
                }
            }
        }
        q.push(-1);  // BFS layer indicator
        while(!q.empty()){
            if(q.front() == -1){
                if(q.size() != 1){
                    q.push(-1);
                    mins++;
                }
                q.pop();
            }
            else{
                i = q.front() / n;
                j = q.front() % n;
                if(i-1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    q.push((i-1) * n + j);
                    freshCount--;
                }
                if(i+1<m && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    q.push((i+1)*n+j);
                    freshCount--;
                }
                if(j-1>=0 && grid[i][j-1]==1){
                    grid[i][j-1] = 2;
                    q.push(i*n+j-1);
                    freshCount--;
                }
                if(j+1<n&&grid[i][j+1]==1){
                    grid[i][j+1] = 2;
                    q.push(i*n+j+1);
                    freshCount--;
                }
                q.pop();
            }
        }
        return freshCount?-1:mins;
    }
};
