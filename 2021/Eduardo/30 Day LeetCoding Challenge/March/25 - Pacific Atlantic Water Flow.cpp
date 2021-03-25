#define MAXN 220
#define pbb pair<bool, bool>

int sX[4] = {1,-1,0,0};
int sY[4] = {0,0,1,-1};

class Solution {
public:
    vector<vector<int>> res, matrix;
    bool atl[MAXN][MAXN], pac[MAXN][MAXN];
    int dp[MAXN][MAXN],n,m;
    
    bool valid(int x, int y){
        return (x>= 0 && y >= 0 && x < n && y<m);
    }
    
    void dfs(int x, int y, bool seen[MAXN][MAXN]){
        seen[x][y] = true;

        
        for(int i=0; i<4; i++){
            int nX = x + sX[i], nY = y + sY[i];

            
            if(valid(nX,nY) && (matrix[x][y] <= matrix[nX][nY]) && !seen[nX][nY])
                dfs(nX,nY, seen);
        }        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return res;
        
        this->matrix = matrix;
        n = matrix.size();
        m = matrix[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        
        for(int i=0; i<n; i++){
            dfs(i,0,pac);
            dfs(i,m-1,atl);
        }
        
        for(int j=0; j<m; j++){
            dfs(0,j,pac);
            dfs(n-1,j,atl);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atl[i][j] && pac[i][j])
                    res.push_back({i,j});
            }
        }
        
        
        return res;
    }
};