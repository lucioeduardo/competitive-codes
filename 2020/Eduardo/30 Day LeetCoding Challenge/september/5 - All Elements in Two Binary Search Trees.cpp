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
    
    void solve(TreeNode* node, vector<int>& v){
        if(node == NULL) return;
        
        solve(node->left,v);
        v.push_back(node->val);
        solve(node->right,v);
    }
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2, res;
        solve(root1,t1);
        solve(root2,t2);
        
        int it1=0, it2=0;
        
        while(it1 < t1.size() && it2 < t2.size()){
            if(t1[it1] < t2[it2]) res.push_back(t1[it1++]);
            else res.push_back(t2[it2++]);
        }
        while(it1 < t1.size()) res.push_back(t1[it1++]);
        while(it2 < t2.size()) res.push_back(t2[it2++]);
        
        return res;
    }
};