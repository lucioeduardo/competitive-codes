class TrieNode{
public:
    bool isEnd;
    unordered_map<char, TrieNode*> child;
    TrieNode() {
        isEnd=false;
    }
};


class WordDictionary {
public:
    TrieNode* trie;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new TrieNode();
    }
    
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = trie;
        
        for(char c: word){
            if(!node->child[c]){
                node->child[c] = new TrieNode();
            }
            node = node->child[c];
        }
        
        node->isEnd = true;
    }
    
    bool solve(TrieNode* node, string& s, int idx){
        if(!node)
            return false;
        
        //cout << node << endl;
        if(idx == s.size())
            return node->isEnd;
        
        if(s[idx] == '.'){
            for(int i=0; i<26; i++){
                char c = 'a'+i;
                if(solve(node->child[c], s, idx+1))
                    return true;
            }
        }else{
            return solve(node->child[s[idx]], s, idx+1);
        }
        
        return false;
    }
    
    bool search(string word) {
        return solve(trie, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */