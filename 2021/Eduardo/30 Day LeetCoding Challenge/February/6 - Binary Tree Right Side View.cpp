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
    
    vector<int> res;
    
    void dfs(TreeNode* node, int dep){
        if(node == NULL) return;
        
        if(res.size() < dep)
            res.push_back(node->val);
        res[dep-1]=node->val;
        
        dfs(node->left, dep+1);
        dfs(node->right, dep+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        res.clear();
        dfs(root,1);
        
        return res;
    }
};