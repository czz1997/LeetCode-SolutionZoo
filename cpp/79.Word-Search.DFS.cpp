// 96.79% faster
// Time complexity O(mn4^L), where m, n are the size of the board and L is the length of the word

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i{}; i<board.size(); i++){
            for(int j{}; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index){
        if(index == word.length() - 1)
            return true;
        
        // mark as visited
        board[i][j] = '#';
        
        if(i > 0 && board[i-1][j] == word[index + 1]){
            // up
            if(dfs(board, i-1, j, word, index + 1))
                return true;
        }
        if(i < board.size() - 1 && board[i+1][j] == word[index + 1]){
            // down
            if(dfs(board, i+1, j, word, index + 1))
                return true;
        }
        if(j > 0 && board[i][j-1] == word[index + 1]){
            // left
            if(dfs(board, i, j-1, word, index + 1))
                return true;
        }
        if(j < board[0].size() - 1 && board[i][j+1] == word[index + 1]){
            // right
            if(dfs(board, i, j+1, word, index + 1))
                return true;
        }
        
        // remove marker
        board[i][j] = word[index];
        return false;
    }
};
