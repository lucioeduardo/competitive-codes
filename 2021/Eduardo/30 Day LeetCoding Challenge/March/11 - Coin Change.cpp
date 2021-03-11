#define MAXV 10010
#define MAXN 15

int dp[MAXN][MAXV];

class Solution {
public:
    
    int n;
    vector<int> coins;
    bool f = false;
    
    
    int solve(int idx, int v){        
        if(v == 0) {
            f=true;
            return 0;
        }
        if(v < 0 || idx >= n) return 9999999;
        if(dp[idx][v] != -1) return dp[idx][v];
        
        return dp[idx][v] = min(1+solve(idx,v-coins[idx]), solve(idx+1,v));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        this->n = coins.size();
        memset(dp,-1,sizeof(dp));
        
        int res = solve(0,amount);
        
        return f ? res : -1;
    }
};