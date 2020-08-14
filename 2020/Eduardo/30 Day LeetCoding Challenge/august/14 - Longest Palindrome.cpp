class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> qtd;
        
        for(char c: s){
            qtd[c]++;
        }
        
        bool f=false;
        int res=0;
        
        for (auto& [key, value]: qtd) {
            if(value % 2) f=true;
            res += value/2;    
        }
        
        res*=2;
        if(f) res++;
        
        return res;
    }
};