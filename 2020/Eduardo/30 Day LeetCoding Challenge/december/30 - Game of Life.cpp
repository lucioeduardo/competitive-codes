int sX[8] = {1,1, 1,-1,-1,-1,0, 0};
int sY[8] = {1,0,-1, 1,0,-1,1,-1};

class Solution {
public:
    
    int n,m;
    
    bool isValid(int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n)
            return false;
        return true;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        
        vector<vector<int>> copy(board);
        

        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int cnt=0;
                for(int k=0; k<8; k++){
                    int nX = i + sX[k], nY = j+sY[k];
                    if(isValid(nX,nY) && copy[nX][nY]){
                        cnt++;
                    }
                }
                                
                if(board[i][j]){
                    if(cnt < 2 || cnt > 3) board[i][j]=0;
                }else{
                    if(cnt == 3) board[i][j]=1;
                }
            }
        }
    }
};