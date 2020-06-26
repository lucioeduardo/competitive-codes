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
    int solve(TreeNode *root, int sum){
        if(root == NULL) return 0;
        
        int v = 10*sum + root->val;
        
        if(root->left == NULL && root->right == NULL) return v;
        
        return solve(root->right, v) + solve(root->left, v);
    }
    
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};