class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        map<int, int> freq;
        
        int c1[26],c2[26];
        
        for(int i=0; i<26; i++) c1[i]=c2[i]=0;
                
        for(char c: word1){
            c1[c-'a']++;
        }
        
        for(char c: word2){
            int v = c-'a';
            if(!c1[v]) return false;
            
            c2[c-'a']++;
        }
        
        for(int i=0; i<26; i++)
            freq[c1[i]]++;
        
        for(int i=0; i<26; i++){
            freq[c2[i]]--;
            
            if(freq[c2[i]] < 0)
                return false;
        }
        
        return true;
    }
};