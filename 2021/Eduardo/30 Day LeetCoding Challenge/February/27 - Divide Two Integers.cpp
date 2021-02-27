class Solution {
public:
    int divide(long long dividend, long long divisor) {
        long long signal = (dividend < 0) ^ (divisor < 0) ? -1:1;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
                
        long long sum=0;
        long long res=0;
        
        for(int i=30; i>=0; --i){
            if(sum + (divisor << i) <= dividend){
                sum += (divisor << i);
                res |= (1LL<<i);
            }
        }
        
        if(signal == -1 && (divisor<<31) <= dividend)
            res = (1<<31);
        
        return res*signal;
    }
};