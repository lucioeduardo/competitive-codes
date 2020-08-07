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

map<int, int> depth;

bool compare(int a, int b){
    if(depth[a] == depth[b])
        return a < b;
        
    
    return depth[a] < depth[b];
}

class Solution {
public:
    map<int, vector<int>> nodes;
    int minX=999999, maxX=0;
    
    
    void solve(TreeNode* node, int x, int dep){
        if(node == NULL) return;
        
                
        depth[node->val]=dep;
        nodes[x].push_back(node->val);
        
        minX = min(minX,x);
        maxX = max(maxX,x);
        
        solve(node->left, x-1, dep+1);
        solve(node->right, x+1, dep+1);
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        
        solve(root, 0, 0);
                
        for(int i=minX; i<=maxX; i++){
            vector<int> v = nodes[i];
            
            
            sort(v.begin(), v.end(), compare);
            res.push_back(v);
        }
        
        return res;
    }
};