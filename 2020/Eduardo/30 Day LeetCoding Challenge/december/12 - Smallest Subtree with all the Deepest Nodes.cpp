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
    map<TreeNode*, int> dep;
        
    int maxDep(TreeNode *node){
        if(node == NULL) return 0;
        
        return dep[node] = 1 + max(maxDep(node->right), maxDep(node->left));
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxDep(root);
        
        while(root != NULL){
            TreeNode* r = root->right, *l = root->left;
            
            if(r == NULL && l == NULL) return root;
            
            if(r == NULL) root = l;
            else if(l == NULL) root = r;
            else{
                //cout << dep[r] << " " << dep[l] << endl;
                
                if(dep[r] == dep[l]) return root;
                
                if(dep[r] > dep[l]) root=r;
                else root=l;
            }
        }
        
        return NULL;
    }
};