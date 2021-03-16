#define MAXN 50050

class Solution {
public:
    
    int dp[MAXN][2];
    vector<int> prices;
    int fee;
    
    int solve(int idx, bool c){
        
        if(idx >= prices.size()) return 0;
        if(dp[idx][c] != -1) return dp[idx][c];
    
        int res = solve(idx+1,c);
        
        if(c)
            res = max(res, -fee+prices[idx] + solve(idx+1,!c));
        else
            res = max(res, -prices[idx] + solve(idx+1, !c));
        
                
        return dp[idx][c] = res;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        this->prices = prices;
        this->fee = fee;
        
        for(int i=0; i<=prices.size(); i++)
            dp[i][0]=dp[i][1]=-1;
        
        return solve(0,false);
    }
};