// 89% faster
// Time complexity O(n)
// Space complexity worst case O(n), best case O(logn)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        preorder(root);
    }
    
    TreeNode* preorder(TreeNode* root){
        if(!root->left && !root->right)
            return root;
        TreeNode* last = root;
        TreeNode* left{root->left}, *right{root->right};
        if(left){
            last->left = nullptr;
            last->right = left;
            last = preorder(left);
        }
        if(right){
            last->left = nullptr;
            last->right = right;
            last = preorder(right);
        }
        
        return last;
    }
};
