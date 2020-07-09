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

#define MAXN 100010
#define ll long long

class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        queue< pair<TreeNode*,int> > q;
        
        q.push({root,0});

        int res = 0;
        
        while(!q.empty()){
            
            int l = q.size();
            
            cout << l << endl;
            
            
            int first = q.front().second;
            int v;
        
            
            while(l--){
                TreeNode* node = q.front().first;
                v = q.front().second;
                q.pop();
                
                if(node->left != NULL){
                    q.push({node->left,2*min(v,1000000000),});
                }
                
                if(node->right != NULL){
                    q.push({node->right,2*min(v,1000000000)+1});
                }
            }
            
            res = max(res,v-first+1);
        }
        
        return res;
    }
};