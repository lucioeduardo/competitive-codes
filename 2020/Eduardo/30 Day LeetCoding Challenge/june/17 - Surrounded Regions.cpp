#define MAXN 1010
int color[MAXN][MAXN];

int sX[4]={1,-1,0, 0};
int sY[4]={0, 0,1,-1};

class Solution {
public:
    int n,m;
    
    int dfs(int x, int y, vector<vector<char>>& board, int c){
        color[x][y] = c;
        
        int ret=1;
        
        for(int i=0; i<4; i++){
            int nX = x + sX[i], nY = y+sY[i];
         
            if(nX < 0 || nY < 0 || nX >= n || nY >= m){
                ret = 0;
                continue;
            }
            
            if(color[nX][nY] == 0 && board[nX][nY] == 'O'){
                ret &= dfs(nX,nY,board,c);
            }                  
        }
        
        return ret;
    }
    
    void setChars(vector<vector<char>>& board, int c){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(color[i][j]==c) board[i][j] = 'X';
            }
        }
        
    }
    
    
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n == 0) return;
        m = board[0].size();
    
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                color[i][j]=0;
            }
        }
        
        int c=1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(color[i][j] == 0 && board[i][j] == 'O'){
                    if(dfs(i,j,board,c)){
                        setChars(board, c);   
                    }
                    c++;
                }
            }
        }
        
    }
};