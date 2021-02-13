int sX[8] = {1,1,1,0,0,-1,-1,-1};
int sY[8] = {0,1,-1,-1,1,0,1,-1};

bool seen[110][110];

struct node{
    int x, y, v;
};

class Solution {
public:
    int n,m;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        memset(seen, false, sizeof(seen));
        
        if(grid[0][0]) return -1;
        
        queue<node> q;
        q.push({0,0,1});
        
        while(!q.empty()){
            node no = q.front(); q.pop();
            
            
            if(no.x == n-1 && no.y == m-1) return no.v;
            
            
            for(int i=0; i<8; i++){
                int nX = no.x+sX[i], nY=no.y+sY[i];

                if((nX >= 0 && nX < n) && (nY >= 0 && nY < m) && grid[nX][nY] == 0 && !seen[nX][nY]){
                    q.push({nX,nY,no.v+1});
                    seen[nX][nY]=true;
                }
            }
        }
        
        return -1;
    }
};