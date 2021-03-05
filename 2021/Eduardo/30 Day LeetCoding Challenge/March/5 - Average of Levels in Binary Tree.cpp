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
    
    void solve(vector<int>& qtd ,vector<double>&res, TreeNode* node, int d){
        if(node == NULL) return;
        
        if(qtd.size() <= d){
            qtd.push_back(1);
            res.push_back(node->val);
        }else{
            qtd[d]++;
            res[d]+=node->val;
        }
        
        solve(qtd,res,node->left,d+1);
        solve(qtd,res,node->right,d+1);
        
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> qtd;
        vector<double> res; 

        solve(qtd, res, root, 0);

        for(int i=0; i<qtd.size(); i++){
           res[i] /= qtd[i];
        }
        return res;
    }
};