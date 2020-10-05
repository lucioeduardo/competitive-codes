class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        int res=0;
        
        for(int i=0; (1<<i) <= N; i++){
            res += (1<<i)*!(N & (1<<i));
        }
        
        return res;
    }
};