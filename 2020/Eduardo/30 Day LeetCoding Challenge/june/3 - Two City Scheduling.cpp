#define MAXN 110

class Solution {
public:
    int n;
    int dp[MAXN][MAXN];
    
    
    int solve(int idx, int a, vector<vector<int>>& costs){        
        if(idx >= n) return 0;
        if(dp[idx][a] != -1) return dp[idx][a];
        
        int b = idx-a;
        
        int res = 999999999;
        
        if(a < n/2)
            res = min(res, costs[idx][0] + solve(idx+1,a+1,costs));
        if(b < n/2)
            res = min(res, costs[idx][1] + solve(idx+1,a,costs));
    
        return dp[idx][a] = res;    
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size();
                
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,costs);
    }
};