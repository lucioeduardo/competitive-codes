#define MAXN 1010

int n,m;

int sX[4] = {1,-1,0,0};
int sY[4] = {0,0,1,-1};

bool vis[MAXN][MAXN];

bool isValid(int x, int y){
    if(x < 0 || x >=n || y < 0 || y >= m) return false;
    return true;
}

void dfs(int x, int y, vector<vector<char>>& grid){
    vis[x][y] = true;
    
    for(int i=0; i<4; i++){
        int nX = x + sX[i];
        int nY = y + sY[i];
        
        if(!isValid(nX,nY))continue;
        if(!(grid[nX][nY] == '1'))continue;
    
        if(!vis[nX][nY]) dfs(nX,nY,grid);
    }
}



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if(!n) return 0;
        
        m = grid[0].size();
        
        
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                vis[i][j]=false;
        
        int res=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == false && grid[i][j] == '1'){
                   // printf("\n\n");
                    res++;
                    dfs(i,j,grid);
                }
            }
        }
        
        return res;
    }
};