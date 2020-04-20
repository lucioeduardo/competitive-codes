/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        
    void insert(TreeNode *node, int value){
        if(value < node->val){
            if(node->left == NULL) node->left = new TreeNode(value);
            else insert(node->left, value);
        }else{
            if(node->right == NULL) node->right = new TreeNode(value);
            else insert(node->right, value);
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        
        for(int i=1; i<preorder.size(); i++){
            insert(root, preorder[i]);
        }
        
        return root;
    }
};