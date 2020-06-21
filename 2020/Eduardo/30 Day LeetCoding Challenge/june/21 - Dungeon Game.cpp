class Solution {
public:
    int n,m;
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        
        int dp[n+1][m+1];
        memset(dp,9999999,sizeof(dp));
        
        dp[n-1][m-1] = max(1, 1 - dungeon[n-1][m-1]);
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 && j == m-1) continue;
                dp[i][j] = max(min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j],1);
            }
        }
        
        return dp[0][0];
    }
};