#define pni pair<Node*, int> 

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
        
        queue<pni> q;
        q.push({root,0});
        
        pni prev;
        
        while(!q.empty()){
            pni p = q.front(); q.pop();
            
            Node *no = p.first;
            int dep = p.second;
            
            if(no->left != NULL) q.push({no->left, dep+1});
            if(no->right != NULL) q.push({no->right, dep+1});
            
            if(no != root){
                
                if(prev.second == dep){
                    prev.first->next = no;
                }else{
                    prev.first->next = NULL;
                }
            }
            
            prev = p;
            
        }
        
        prev.first->next = NULL;
        
        return root;
    }
};