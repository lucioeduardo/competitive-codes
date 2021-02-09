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
    
    int sum_r = 0;
    
    int solve(TreeNode * node){
        if(node == NULL) return 0;
        
        int r = solve(node->right);
        
        int v = node->val;  
        node->val = v + sum_r;
        sum_r += v;
        
        int l = solve(node->left);
        
        return v + r + l;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        sum_r=0;
        solve(root);
        
        return root;
    }
};