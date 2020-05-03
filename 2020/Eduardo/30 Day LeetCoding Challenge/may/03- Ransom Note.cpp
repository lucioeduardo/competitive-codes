class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int qtd[260];
        
        memset(qtd,0,sizeof(qtd));
        
        for(char c: magazine){
            qtd[c]++;
        }
        
        for(char c: ransomNote){
            qtd[c]--;
            if(qtd[c] < 0) return false;
        }
        
        return true;
    }
};