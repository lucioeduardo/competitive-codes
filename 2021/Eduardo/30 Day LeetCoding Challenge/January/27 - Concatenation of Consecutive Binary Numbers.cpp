#define MOD 1000000007

class Solution {
public:
    int concatenatedBinary(int n) {
        int res = 0;
        int j=0;
        int pow2=1;
        
        
        
        for(int i=n; i>=1; i--){
            int k=i;
            
            while(k>0){
                if(k%2){
                    res += pow2;
                    
                    res = res % MOD;
                }
                
                k/=2;
                j++;
                pow2 = (pow2*2)%MOD;
            }
        }
        
        return res;
    }
};