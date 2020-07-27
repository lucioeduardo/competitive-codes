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
    int n, pIdx;
    vector<int> in, post;
    
    TreeNode* buildNode(int beg, int end){        
        if(beg > end)
            return NULL;
        
        TreeNode *node = new TreeNode(post[pIdx--]);
        
        if(beg == end)
            return node;
        
        int iIdx = search(node->val);
                 
        node->right = buildNode(iIdx+1,end);
        node->left = buildNode(beg,iIdx-1);
        
        return node;
    }
    
    int search(int val){
        for(int i=0; i<n; i++){
            if(in[i] == val)
                return i;
        }
        return -1;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder;
        post = postorder;
        
        n = inorder.size();
        pIdx = n-1;
        
        if(n == 0) return NULL;
        
        return buildNode(0,n-1); 
    }
};