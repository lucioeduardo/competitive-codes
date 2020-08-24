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
    
    int solve(TreeNode *node, bool l){
        if(node == NULL)
            return 0;
        
        if(node->right == NULL && node->left == NULL)
            return l ? node->val : 0;
        
        return solve(node->left, true) + solve(node->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
};