class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][2];
    
        dp[n][0] = dp[n][1] = 0;
        
        for(int i=n-1; i>=0; i--){
            dp[i][0] = max(dp[i+1][0], dp[i+1][1] - prices[i]);
            dp[i][1] = max(dp[i+1][1], dp[i+1][0] + prices[i]);
            
            cout << dp[i][0] << " " << dp[i][1] << endl;
         }
        
        return dp[0][0];
    }
};