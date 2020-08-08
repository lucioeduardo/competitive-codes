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
#define MAXN 1010

class Solution {
public:
        
    int solve(TreeNode *node, int s){
        if(node == NULL) return 0;
        
        int res = 0;

        if(s == node->val) {
            res++;
        }
        
        return res + solve(node->right, s-node->val) + solve(node->left, s-node->val);
    }
    
    
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        
        return solve(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};