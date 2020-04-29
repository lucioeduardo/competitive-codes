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
    int res=-999999;
    
    int solve(TreeNode* root) {
        if(root == NULL) return 0;
        
        int esq = max(solve(root->left),0);
        int dir = max(solve(root->right),0);
                
        res = max(res, esq + dir + root->val);
        
        return max(esq,dir) + root->val;
    }
    
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        
        return res;
    }
};