class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        
        int at=0;
        int prev=0;
        
        for(char c: s){
            int v = 0;
            
            if(c == 'M') v = 1000;
            else if(c == 'D') v=500;
            else if(c == 'C') v=100;
            else if(c == 'L') v=50;
            else if(c == 'X') v=10;
            else if(c == 'V') v=5;
            else v=1;
            
            if(v < at){
                res += at;
                at=v;
            }else if(at == v){
                at += v;
            }else{
                at = v-at;
            }
        }
        
        res += at;
        
        return res;
    }
};