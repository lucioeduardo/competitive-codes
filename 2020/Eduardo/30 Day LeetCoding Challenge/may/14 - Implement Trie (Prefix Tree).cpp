class Node{
public:
    Node *children[26];
    bool isEnd;
    
    Node(){
        isEnd = false;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
    }
};

class Trie {
public:
    Node* root; 
    /** Initialize your data structure here. */
    Trie() {
       root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *no = root;
        
        for(char c: word){
            if(no->children[c - 'a'] == NULL) {
                no->children[c-'a']=new Node();
            }
            
            no = no->children[c-'a'];
        }
        
        no->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *no = root;
        
        for(char c: word){
            if(no->children[c-'a'] == NULL)
                return false;
            no = no->children[c-'a'];
        }
        
        return no!=NULL && no->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *no = root;
        
        for(char c: prefix){
            if(no->children[c-'a'] == NULL)
                return false;
            no = no->children[c-'a'];
        }
        
        return true;
    }
};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */