#define pii pair<TreeNode*, TreeNode*>

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
    vector<int> inOrder;
    
    int a,b;
    
    void getInOrder(TreeNode* node){
       // cout << node << endl;
        if(node == NULL) return;
        getInOrder(node->left);
        inOrder.push_back(node->val);
        getInOrder(node->right);
    }
    
    void solve(TreeNode* node){
        if(node == NULL) return;
        solve(node->left);
        solve(node->right);
        
        if(node->val == a) node->val=b;
        else if(node->val == b) node->val=a;
    }
    
    void recoverTree(TreeNode* root) {
        getInOrder(root);
        
        a=-1; b=-1;
        
        for(int i=0; i<inOrder.size(); i++){
         //   cout << inOrder[i] << endl;
            
            if(a==-1 && inOrder[i] > inOrder[i+1]) a=inOrder[i];
            if(i > 0 && inOrder[i] < inOrder[i-1]) b=inOrder[i];
        }
        
       // cout << a << " " << b;
        
        solve(root);
    }
};
