#define MAXN 10010

int dp[MAXN][MAXN/2][2];

class Solution {
public:
    int n;
    vector<int> prices;
    
    int maxProfit(int k, vector<int>& prices) {
        this->prices = prices;
        n = prices.size();
        
        
        if(k > n/2){
            int res = 0;
            
            for(int i=1; i<n; i++){
                res += max(0, prices[i]-prices[i-1]);
            }
            
            return res;
        }
                
        for(int i=0; i <= k; i++){
            for(int j=n; j>=0; j--){
                if(j == n) dp[j][i][0] = dp[j][i][1] = 0;
                else{
                    dp[j][i][0] = i == 0 ? dp[j+1][i][0] : max(dp[j+1][i][0], -prices[j]+dp[j+1][i-1][1]);
                    dp[j][i][1] = max(dp[j+1][i][1], prices[j]+dp[j+1][i][0]);                    
                }
            }
        }
                
        return dp[0][k][0];
    }
};