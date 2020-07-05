class Solution {
public:
    int hammingDistance(int x, int y) {
        int dif = x^y;
        
        int res=0;
        
        for(int i=0; i < 32 && (1<<i) <= dif; i++){
            if((1<<i) & dif) res++;
        }
        
        return res;
    }
};