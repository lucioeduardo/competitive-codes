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
    int n;
    
    
    int solve(TreeNode *node){
        int v=999999999;
        
        
        if(node->left != NULL)
            v = solve(node->left);  
        
        n--;  
        if(n == 0)
            return node->val;
    
        if(node->right != NULL)
            v = min(v, solve(node->right));
        
        return v;
    }       
    
    int kthSmallest(TreeNode* root, int k) {
        n=k;
        
        return solve(root);
    }
};