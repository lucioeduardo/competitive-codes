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
    
    int idx=-1;
    vector<int> voyage;
    vector<int> res;
    
    bool solve(TreeNode *root){
        if(root == NULL) return true;
        
        idx++;
        
        if(root->val != voyage[idx])
            return false;
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        if(left != NULL && left->val != voyage[idx+1]){
            res.push_back(root->val);
            swap(root->left,root->right);
        }
        
        return solve(root->left) && solve(root->right);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        this->voyage = voyage;
        bool f = solve(root);
        
        vector<int> fail = {-1};
        
        return f ? res : fail;
    }
};