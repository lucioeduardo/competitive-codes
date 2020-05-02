class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int val[260];
        memset(val,0,sizeof(val));
        
        for(char c : J){
            val[c]=1;
        }
        
        int res = 0;
        
        for(char c: S){
            res += val[c];
        }
        
        return res;
    }
};