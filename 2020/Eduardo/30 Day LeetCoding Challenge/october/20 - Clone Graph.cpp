/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    set<Node*> seen;
    map<Node*, Node*> mp;
    
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        seen.insert(node);
        Node* clone = new Node(node->val);
        mp[node]=clone;
        
        for(int i=0; i<node->neighbors.size(); i++){
            Node* u = node->neighbors[i];
            
            if(!seen.count(u)){
                Node *v = cloneGraph(u);
                clone->neighbors.push_back(v);
            }else{
                clone->neighbors.push_back(mp[u]);
            }
            
        }
        
        return clone;
        
    }
};