
class Solution {
public:
    int res=0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        dfs(root);
        
        return this->res;
    }
    
    int dfs(TreeNode *no){
        if(no == NULL) return 0;
              
        int left = dfs(no->left);
        int dir = dfs(no->right);
        
        this->res = max(res, left+dir);
        
        return max(left,dir) + 1;
    }
};