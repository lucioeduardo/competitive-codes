class TrieNode{
public:
    map<char, TrieNode*> children;
    bool isEnd;
    
    TrieNode(){
        isEnd = false;
    }
};

class Trie{
public:
    TrieNode *parent;
    
    Trie(){
        parent = new TrieNode();
    }
    void add(string &a){
        TrieNode *current = parent;
        for(int i=a.length()-1; i>=0; i--){
            char c = a[i];
            if(current->children.find(c) == current->children.end()){
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        
        current->isEnd = true;
    }
    
    bool exists(string &a) {
        TrieNode *current = parent;
        for(int i=a.length()-1; i>=0; i--){
            char c = a[i];
            
            if(current->children.find(c) == current->children.end()){
                return false;
            }
            current = current->children[c];
            if(current->isEnd) return true;
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie* t = new Trie();
    string s = "";
    int max_l=0;
    
    
    StreamChecker(vector<string>& words) {
        for(string w: words){
            t->add(w);
            if(w.length() > max_l) max_l = w.length();
        }
    }
    
    bool query(char letter) {
        s += letter;
        
        if(s.length() > max_l)
            s.erase(s.begin());
            
        return t->exists(s);
    }
};
