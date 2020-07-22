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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            pair<TreeNode*, int> v = q.front(); q.pop();
            
            if(v.first == NULL) continue;
            
            if(res.size() <= v.second){
                vector<int> aux;
                res.push_back(aux);
            }
            
            res[v.second].push_back(v.first->val);
            
            q.push({v.first->left, v.second+1});
            q.push({v.first->right, v.second+1});
        }
        
        for(int i=1; i<res.size(); i+=2){
            reverse(res[i].begin(), res[i].end());
        }
        
        return res;
    }
};