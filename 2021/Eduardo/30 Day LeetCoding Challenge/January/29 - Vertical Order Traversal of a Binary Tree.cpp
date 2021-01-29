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

#define pii pair<int,int>

class Solution {
public:
    
    void solve(TreeNode *node, int x, int y, map<int, vector<pii>>& m){
        if(node == NULL) return;
        
        m[x].push_back({y,node->val});
        
        solve(node->left, x-1, y+1, m);
        solve(node->right, x+1, y+1, m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pii>> m;
        vector<vector<int>> res;
        
        solve(root, 0, 0, m);
        
        for(auto &p: m){
            sort(p.second.begin(), p.second.end());
            
            vector<int> v;
            
            for(pii p: p.second){
                v.push_back(p.second);
            }
            
            res.push_back(v);
        }
        
        return res;
    }
};