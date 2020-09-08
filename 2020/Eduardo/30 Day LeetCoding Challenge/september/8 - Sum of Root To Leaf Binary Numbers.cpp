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
    int res = 0;
    
    
    void solve(TreeNode* node, int sum) {
        int v = node->val;
        
        sum = 2*sum+v;
        
        if(node->left == NULL && node->right == NULL)
            res += sum;
        
        if(node->left != NULL)
            solve(node->left, sum);
        
        if(node->right != NULL)
            solve(node->right, sum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        solve(root, 0);
        
        return res;
    }
};