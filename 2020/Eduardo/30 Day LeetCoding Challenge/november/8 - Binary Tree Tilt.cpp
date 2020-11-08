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
    
    int res=0;
    
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        
        res += abs(l-r);
        
        return l+r+root->val;
    }
    
    
    int findTilt(TreeNode* root) {
        res=0;
        
        solve(root);
        
        return res;
    }
};