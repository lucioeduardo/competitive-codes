class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int r = 1%K;
        int res=1;
        
        if(K % 2 == 0 || K%5 == 0) return -1;
        
        while(r!=0){
            res++;
            r = (r*10+1)%K;
        }
        
        return res;
    }
};