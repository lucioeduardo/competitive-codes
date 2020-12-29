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
    
    int solve(TreeNode *node, vector<int> count){
        if(node == NULL) return 0;
        
        count[node->val]++;
        
        if(node->left == NULL && node->right == NULL){
            bool flag=true;
            
            for(int num: count){
                if(num % 2){
                    if(!flag) return 0;
                    flag = false;
                }
            }
            
            return 1;
        }
        
        
        
        return solve(node->left, count) + solve(node->right, count);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        return solve(root, vector<int>(10,0));
    }
};