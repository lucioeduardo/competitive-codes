/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    
    
    TreeNode* addNode(TreeNode *node, int val){
        if(node == NULL) return new TreeNode(val);
        
        if(val > node->val) node->right = addNode(node->right, val);
        else node->left = addNode(node->left, val);
        
        return node;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> v;
        if(root == NULL) return "";
        

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *t = q.front();q.pop();
            
            v.push_back(t->val);
            
            if(t->left != NULL) q.push(t->left);
            if(t->right != NULL) q.push(t->right);
        }
        
        
        
        string res = to_string(v[0]);
        
        for(int i=1; i<v.size(); i++) res += ";" + to_string(v[i]);
        
        cout << res << endl;
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        if(data.empty()) return root;
        
        string act="";
        
        for(char c: data){
            if(c == ';'){
                int val = stoi(act);
                root = addNode(root, val);
                act = "";
            }else{
                act += c;    
            }
            
        }
        
        int val = stoi(act);
        root = addNode(root, val);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;