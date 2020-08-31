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
    
    void insertNode(TreeNode* node, TreeNode* right){
        if(node->right == NULL)
            node->right = right;
        else
            insertNode(node->right, right);
    }
    
    
    TreeNode* deleteNode(TreeNode* node, int key) {
        if(node == NULL) return node;
        
        if(node->val == key){
            TreeNode* left = node->left;
            TreeNode* right = node->right;

            if(right == NULL){
                node = left;
            }else{
               node = right;
               TreeNode* rightLeft = node->left;

               if(left != NULL){
                node->left = left;
                insertNode(node->left, rightLeft); 
               }

            }
        }else if(key > node->val){
            node->right = deleteNode(node->right, key);
        }else{
            node->left = deleteNode(node->left, key);
        }
        
        return node;
    }
};