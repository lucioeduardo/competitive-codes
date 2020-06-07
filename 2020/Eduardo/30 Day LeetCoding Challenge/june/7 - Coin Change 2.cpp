#define MAXV 5010
#define MAXN 510

int dp[MAXN][MAXV];

class Solution {
public:
    int n;
    
    int solve(int idx, int val, vector<int>&coins){
        if(idx >= n || val < 0)
            return 0;
        if(val == 0)
            return 1;
        if(dp[idx][val] != -1) return dp[idx][val];
        
        return dp[idx][val] = solve(idx,val-coins[idx],coins) + solve(idx+1,val,coins);
    }
    
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        
        n = coins.size();
        
        for(int i=0; i<n; i++)
            for(int j=0; j<=amount; j++)
                dp[i][j]=-1;
        
        return solve(0,amount,coins);
    }
};