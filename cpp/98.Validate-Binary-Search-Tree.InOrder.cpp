// 67% faster
// O(n)

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
    bool isValidBST(TreeNode* root) {
        TreeNode* last = nullptr;
        return inorder(root, last);
    }
    
    bool inorder(TreeNode* root, TreeNode* &last){
        if(root == nullptr)
            return true;
        if(!inorder(root->left, last))
            return false;
        if(last && root->val <= last->val)
            return false;
        last = root;
        return inorder(root->right, last);
    }
};
