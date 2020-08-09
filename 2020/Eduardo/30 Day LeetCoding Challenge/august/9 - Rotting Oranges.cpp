int sX[4] = {1,-1,0,0};
int sY[4] = {0,0,1,-1};

int n,m;

bool isValid(int x, int y){
    return (x>=0 && y>=0 && x < n && y < m);
}

class Solution {
public:
    vector<vector<int>> grid;
    bool seen[15][15];
    
    void dfs(int x, int y){
        cout << x << " " << y << endl;
        for(int i=0; i<4; i++){
            int nX = x + sX[i], nY = y + sY[i];
        
            if(isValid(nX,nY) && grid[nX][nY] != 0){
                if(grid[nX][nY] == 1 ||  grid[nX][nY] > grid[x][y] + 1){
                    grid[nX][nY] = grid[x][y] + 1;
                    dfs(nX,nY);
                }
            }
        }
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        this->grid = grid;
        
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2)
                    dfs(i,j);
            }
        }
        
        int res=2;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << this->grid[i][j] << " ";
                if(this->grid[i][j] == 1)
                    return -1;
                else if(this->grid[i][j] != 0)
                    res = max(res,this->grid[i][j]);
            }
            cout << endl;
        }
        
        return res-2;
    }
};