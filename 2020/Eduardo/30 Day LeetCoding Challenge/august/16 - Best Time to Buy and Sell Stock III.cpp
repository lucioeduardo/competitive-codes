
int dp[100100][3][2];

class Solution {
public:
    int n;
    vector<int> prices;
    
    int solve(int idx, int q, bool c){
        if(idx == n) return 0;
        if(dp[idx][q][c] != -1) return dp[idx][q][c];
        
        int res = 0;
        
        if(!c && q > 0)
            res = max(res, solve(idx+1, q-1, true) - prices[idx]);
        
        if(c){
            res = max(res, solve(idx+1,q,false) + prices[idx]);
        }
        
        res = max(res, solve(idx+1,q,c));
        
        return dp[idx][q][c] = res;
    }
    
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        this->prices = prices;
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,2,false);
    }
};