class Solution {
public:
    
    int solve(int x, int y, int n, int m, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(x == n-1 && y == m-1) return grid[x][y];
        if(dp[x][y] != -1) return dp[x][y];
        
        int res = 999999999;
        
        if(x < n-1) res = min(res, solve(x+1,y,n,m,dp,grid));
        if(y < m-1) res = min(res, solve(x,y+1,n,m,dp,grid));
        
        return dp[x][y] = res + grid[x][y];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<int> > dp(n);
        for(int i = 0;i<n ;i++){
           for(int j=0; j<m; j++){
               dp[i].push_back(-1);
           }
        }
        
        return solve(0,0,n,m,dp,grid);
    }
};