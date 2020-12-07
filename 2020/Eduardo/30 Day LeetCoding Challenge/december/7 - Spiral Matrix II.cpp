class Solution {
public:
    int n;
    
    bool isValid(int x, int y){
        if(x >= 0 && x < n && y >= 0 && y < n)
            return true;
        return false;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        this->n=n;
        vector<vector<int>> res;
        
        for(int i=0; i<n; i++){
            vector<int> v(n,0);
            res.push_back(v);
        }
        
        int sX[4] = {0,1,0,-1};
        int sY[4] = {1,0,-1,0};
        
        int x=0, y=0;
        int s=0;
        
        for(int i=1; i<=n*n; i++){
            res[x][y] = i;
            
            int nX,nY;
            nX = x + sX[s];
            nY = y + sY[s];
            
            if(!isValid(nX,nY) || res[nX][nY] != 0){
                s = (s+1)%4;
                nX = x + sX[s];
                nY = y + sY[s];
            }
            
            x=nX;
            y=nY;
        }
        
        return res;
    }
};