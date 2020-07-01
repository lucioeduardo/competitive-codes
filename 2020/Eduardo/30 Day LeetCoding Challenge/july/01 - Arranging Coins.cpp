class Solution {
public:
    int arrangeCoins(int n) {
        int l=0, r=n;
        
        int res;
        
        while(l <= r){
            long long m = (l+r)/2;
            
            long long v = m*(m+1)/2;
            
            if(v > n){
                r=m-1;
            }
            else{
                res=m;
                l=m+1;
            }
        }
        
        return res;
    }
};