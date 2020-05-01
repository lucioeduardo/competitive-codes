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
    
    bool solve(TreeNode* node, vector<int>&arr, int idx){
        if(node == NULL || idx == arr.size()) return false;
        if(node->val != arr[idx]) return false;
        
        if(node->right == NULL && node->left == NULL && idx == arr.size()-1) return true;
        
        return solve(node->right, arr, idx+1) || solve(node->left, arr, idx+1);
    }
    
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return solve(root, arr, 0);
    }
};