class Solution {
public:
    char findTheDifference(string s, string t) {
        int qtd[26];
        
        memset(qtd,0,sizeof(qtd));
        
        for(char c: s){
            qtd[c-'a']++;
        }
        
        for(char c: t){
            qtd[c-'a']--;
            if(qtd[c-'a'] < 0) return c;
        }
        
        return 'x';
    }
};