class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][6];
        
        for(int i=1; i<=5; i++)
            dp[1][i] = i;
        
        for(int i=2; i<= n; i++){
            for(int j=1; j<=5; j++){
                dp[i][j]=dp[i-1][j];
                if(j > 1) dp[i][j] += dp[i][j-1];
            }
        }
        
        return dp[n][5];
    }
};