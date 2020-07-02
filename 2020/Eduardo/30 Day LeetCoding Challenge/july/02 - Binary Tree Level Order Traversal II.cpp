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
    
    void solve(TreeNode* root, vector<vector<int>>& res, int depth){
        if(root == NULL) return;
        if(res.size() <= depth) {
            vector<int> v;
            res.push_back(v);
        }
        res[depth].push_back(root->val);
        
        solve(root->left, res, depth+1);
        solve(root->right, res, depth+1);
        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        
        solve(root,res,0);
        reverse(res.begin(),res.end());
        
        return res;
    }
};