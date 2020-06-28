#define MAXN 100100

class Solution {
public:
    
    int dp[MAXN];
    
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    
    int numSquares(int n) {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int res = 99999999;
        
        for(int i=1; i*i <= n; i++){
            res = min(res, numSquares(n-i*i));
        }
        
        return dp[n] = 1+res;
    }
};