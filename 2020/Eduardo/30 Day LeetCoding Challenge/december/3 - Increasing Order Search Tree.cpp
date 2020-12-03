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
    
    TreeNode *newRoot;
    TreeNode *it;
    
    void solve(TreeNode* node){  
        if(node->left != NULL){
            solve(node->left);
        }
        
        if(node->left == NULL && newRoot == NULL){
            newRoot = node;
            it = newRoot;
            it->left=NULL;            
        }else{
            it->left=NULL;
            it->right = node;
            it = it->right;
        }
        
        
        if(node->right != NULL){
            solve(node->right);
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        newRoot = NULL;
        
        solve(root);
        it->left=NULL;
        it->right = NULL;
    
        return newRoot;
    }
};