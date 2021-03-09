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
    
    int v,d;
    
    void solve(TreeNode* node, int dep){
        if(node == NULL) return;
        
        if(dep == d-1){
            TreeNode *left = new TreeNode(v);
            left->left = node->left;
            
            TreeNode *right = new TreeNode(v);
            right->right = node->right;
            
            node->left = left;
            node->right = right;
            
            return;
        }
        
        solve(node->left, dep+1);
        solve(node->right, dep+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        this->v = v;
        this->d = d;
        
        if(d == 1){
            TreeNode *no = new TreeNode(v);
            no->left = root;
            
            root = no;
        }
        
        
        solve(root, 1);
        
        return root;
    }
};