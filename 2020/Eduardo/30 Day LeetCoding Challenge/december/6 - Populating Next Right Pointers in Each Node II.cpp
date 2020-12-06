/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        queue< pair<Node*, int> > q;
        
        q.push({root, 0});
        
            
        pair<Node*, int> prev = {root,0};
        
        while(!q.empty()){
            Node *n = q.front().first;
            int dep = q.front().second;
            
            q.pop();
            
            if(prev.second == dep){
                prev.first->next = n;
            }else{
                prev.first->next = NULL;
            }
            
            if(n->left != NULL)
                q.push({n->left, dep+1});
            if(n->right != NULL)
                q.push({n->right, dep+1});
            
            
            prev = {n,dep};
        }
        
        if(root->next == root) root->next = NULL;
            
        return root;
    }
};