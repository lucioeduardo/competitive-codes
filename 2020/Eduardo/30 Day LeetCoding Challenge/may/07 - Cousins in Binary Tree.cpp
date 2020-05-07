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
    int depX, depY;
    TreeNode *pX, *pY;
    
    void dfs(TreeNode *node, TreeNode *parent, int x, int y, int depth){
        if(node == NULL) return;
        
        if(node->val == x){
            depX = depth;
            pX = parent;
        }
        
        if(node->val == y){
            depY = depth;
            pY = parent;
        }
        
        dfs(node->left, node, x, y, depth+1);
        dfs(node->right, node, x, y, depth+1);
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, x, y, 0);
        
        return (depX == depY) && (pX != pY);
    }
};