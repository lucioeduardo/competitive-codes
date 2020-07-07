#define MAXN 110

int sX[4] = {1,-1,0,0};
int sY[4] = {0,0,1,-1};

class Solution {
public:
    int res=0;
    bool seen[MAXN][MAXN];
    int n,m;
    
    void dfs(vector<vector<int>>& grid, int x, int y){
        seen[x][y] = true;
        
        for(int i=0; i<4; i++){
            int nX = x + sX[i], nY = y + sY[i];
            
            if(nX < 0 || nX >=n || nY < 0 || nY >=m || grid[nX][nY] == 0)
                res++;
            else if(grid[nX][nY] == 1 && !seen[nX][nY]){
                dfs(grid,nX,nY);
            }
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        if(!n) return 0;
        
        m = grid[0].size();
        
        memset(seen,false,sizeof(seen));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m; j++){
                if(grid[i][j] && !seen[i][j]){
                    dfs(grid,i,j);
                }
            }
        }
        
        return res;
    }
};