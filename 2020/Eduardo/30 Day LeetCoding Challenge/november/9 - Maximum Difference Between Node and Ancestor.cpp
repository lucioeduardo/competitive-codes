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

#define pii pair<int,int>

class Solution {
public:
    
    int res;
    
    pii solve(TreeNode *node){
        if(node == NULL)
            return {-1,-1};
        
        int v = node->val;
        
        if(node->left == NULL && node->right == NULL)
            return {v, v};
        
        
        
        pii left = solve(node->left);
        pii right = solve(node->right);
        pii result;
        
        
        if(node->right == NULL)
            result = left;
        else if(node->left == NULL)
            result = right;
        else{
            int a = min(left.first,right.first);
            int b = max(left.second,right.second);
            
            result = {a,b};
        }
        
        
        res = max(res, max(abs(v-result.first), abs(v-result.second)));
        
        return {min(result.first,v), max(result.second,v)};
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        res=0;
        
        solve(root);
        
        return res;
    }
};