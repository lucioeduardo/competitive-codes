class Solution {
public:
    int maxPower(string s) {
        char prev='-';
        
        int qtd=1;
        int res=1;    
        
        for(char c: s){
            if(c == prev) qtd++;
            else{
                qtd=1;
            }
            
            res = max(res,qtd);
            
            prev=c;
        }
        
        return res;
    }
};