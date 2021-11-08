// 53% faster
// Time complexity O(M)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose
        for(int i{}; i<matrix.size(); i++){
            for(int j{i+1}; j<matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // flip
        for(int i{}; i<matrix.size(); i++){
            for(int j{}; j<matrix.size() / 2; j++){
                swap(matrix[i][j], matrix[i][matrix.size()-j-1]);
            }
        }
    }
};
