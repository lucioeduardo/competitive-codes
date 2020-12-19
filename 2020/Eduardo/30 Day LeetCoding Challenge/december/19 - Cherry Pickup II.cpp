#include <cstring>

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dp[n+2][m+2][m+2];
        memset(dp,0,sizeof(dp));
        
        for(int k=n; k>=1; k--){
            for(int i=1; i<=m; i++){
                for(int j=i+1; j<=m; j++){
                    int max_v = max(dp[k+1][i+1][j], max(dp[k+1][i+1][j+1], dp[k+1][i+1][j-1]));
                    max_v = max(max_v, max(dp[k+1][i][j], max(dp[k+1][i][j+1], dp[k+1][i][j-1])));
                    max_v = max(max_v, max(dp[k+1][i-1][j], max(dp[k+1][i-1][j+1], dp[k+1][i-1][j-1])));
                    
                    
                    dp[k][i][j] = (i == j) ? 0 : max_v + grid[k-1][i-1] + grid[k-1][j-1];
                    
                }
            }
        }
        
        return dp[1][1][m];
    }
};