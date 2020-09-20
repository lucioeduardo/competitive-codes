#define MAXN 25

int sX[4]={0,0,-1,1};
int sY[4]={1,-1,0,0};

class Solution {
public:
    vector<vector<int>> grid;
    int n,m;
    
    int dfs(int x, int y, int mask, int zeros){
        int res=0;
        mask |= 1<<(m*x+y);
        
        if(grid[x][y] == 2) return !zeros;
        
        for(int i=0; i<4; i++){
            int nX = x+sX[i];
            int nY = y+sY[i];
            
            int q = m*nX + nY;
            
            if(valid(nX,nY) && !((1<<q) & mask) && grid[nX][nY] != -1){
                res += dfs(nX,nY,mask,zeros-1);
            }
        }
        
        return res;
    }
    
    bool valid(int x, int y){
        if(x < 0 || y < 0 || x >= n || y >= m) return false;
        return true;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        if(!n) return 0;
        m = grid[0].size();
        
        int a,b;
        
        int nZeros=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    a=i;
                    b=j;
                }else if(grid[i][j] == 0){
                    nZeros++;
                }
            }
        }
        
        return dfs(a,b,0,nZeros+1);
    }
};