#define MAXN 10010

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
    int it=0;
    map<TreeNode*, int> idx;
    int dp[MAXN][2];
    
    int solve(TreeNode* no, bool f){
        if(no == NULL) return 0;
        int res = 0;
        
        if(idx.count(no) == 0) idx[no] = it++;
        if(dp[idx[no]][f] != -1) return dp[idx[no]][f];
        
        if(!f) res = max(res, no->val + solve(no->right, true) + solve(no->left, true));
    
        res = max(res, solve(no->right, false) + solve(no->left, false));
                
        return dp[idx[no]][f] = res;
    }
    
    int rob(TreeNode* root) {
        memset(dp,-1,sizeof(dp));
        
        return solve(root, false);
    
    }
};