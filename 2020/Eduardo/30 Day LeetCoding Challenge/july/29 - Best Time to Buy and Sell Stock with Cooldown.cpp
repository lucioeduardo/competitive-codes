class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if(!n) return 0;
        
        int dp[n][3];
        
        dp[n-1][0] = 0;
        dp[n-1][1] = prices[n-1];
        dp[n-1][2] = 0;
        
        for(int i=n-2; i>=0; i--){
            dp[i][0] = max(dp[i+1][1] - prices[i], dp[i+1][0]);
            dp[i][1] = max(prices[i]+dp[i+1][2], dp[i+1][1]);
            dp[i][2] = dp[i+1][0];
        }
        
        return dp[0][0];
    }
};