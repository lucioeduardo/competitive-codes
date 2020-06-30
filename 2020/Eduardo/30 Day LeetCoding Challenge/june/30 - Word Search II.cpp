const int ALPH = 26; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPH]; 
  
    bool isEnd; 
}; 
  
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEnd = false; 
  
    for (int i = 0; i < ALPH; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  

void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *node = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!node->children[index]) 
            node->children[index] = getNode(); 
  
        node = node->children[index]; 
    } 
  
    node->isEnd = true; 
} 

bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *node = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!node->children[index]) 
            return false; 
  
        node = node->children[index]; 
    } 
  
    return (node != NULL && node->isEnd); 
} 

bool isPrefix(struct TrieNode *root, string key) 
{ 
    struct TrieNode *node = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!node->children[index]) 
            return false; 
  
        node = node->children[index]; 
    } 
  
    return true; 
} 


class Solution {
public:
    
    int n,m;
    struct TrieNode *trie;
    set<string> res;
    
    
    void solve(int i, int j, string act,vector<vector<char>>& board, vector<string>& words){
        
        if(i < 0 || i>=n || j >= m || j < 0) return;
        if(board[i][j] == '-')return;
        char c = board[i][j];
        
        string str = act + c;
        
        if(!isPrefix(trie,str)) return;
        
        if(search(trie,str))
            res.insert(str);
        
        board[i][j]='-';
        solve(i+1,j,str,board,words);
        solve(i,j+1,str,board,words);
        solve(i-1,j,str,board,words);
        solve(i,j-1,str,board,words);
        board[i][j] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        vector<string> res_vec;
        
        n = board.size();        
        m = board[0].size();
        
        trie = getNode(); 
        
        for(string s: words){
            insert(trie,s);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                solve(i,j,"",board,words);
            }
        }
        
        for(set<string>::iterator it = res.begin(); it!=res.end(); it++)
            res_vec.push_back(*it);
        
        
        return res_vec;
    }
    
};