#define MAXN 32

class Solution {
public:
    
    int dp[MAXN][MAXN];
    
    int solve(int a, int b){
        if(a >= b) return 1;
        if(dp[a][b] != -1) return dp[a][b];
        
        int res=0;
        
        for(int i=a; i<=b; i++){
            res += solve(a,i-1)*solve(i+1,b);
        }
        
        return dp[a][b] = res;
    }
    
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        
        return solve(1,n);
    }
};