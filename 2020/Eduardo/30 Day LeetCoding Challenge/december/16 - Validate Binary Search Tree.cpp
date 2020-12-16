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
    bool res=true;
    
    pair<int,int> solve(TreeNode *root){
        TreeNode* left = root->left, *right = root->right;
        pair<int,int> p;
        
        int min_v=root->val, max_v = root->val;
        
        
        if(left){
            p = solve(left);
            int a = p.second;
                        
            if(a >= root->val)
                res = false;
            
            min_v = min(min_v, p.first);
        }
        
        if(right){
            p = solve(right);
            int a = p.first;
                        
            if(a <= root->val)
                res = false;
            
            max_v = max(max_v, p.second);
        }
        
        return {min_v,max_v};
    }
    
    
    bool isValidBST(TreeNode* root) {
        res = true;
        
        solve(root);
        
        return res;
    }
};