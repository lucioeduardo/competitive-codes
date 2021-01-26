#define MAXN 110

int sX[4] = {1,0,-1,0};
int sY[4] = {0,1,0,-1};

class Solution {
public:
    int seen[MAXN][MAXN],n,m;
    vector<vector<int>> heights;
    
    bool isValid(int x, int y){
        return (x >= 0 && x < n && y >=0 && y < m);
    }
    
    bool test(int x, int y, int k){
        //cout << x << " " << y << " " << k << endl;
        if(x == n-1 && y == m-1) return true;
        
        seen[x][y] = true;
        
        bool res = false;
        
        for(int i=0; i<4; i++){
            int nX=x+sX[i], nY=y+sY[i];
            
            //cout << nX << " " << nY << endl;
            
            if(isValid(nX,nY) && !seen[nX][nY] && (abs(heights[x][y] - heights[nX][nY]) <= k))
                res = res || test(nX,nY,k);
        }
        
        return res;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        this->heights = heights;
        
        n = heights.size();
        m = heights[0].size();
        
        int l=0, r=1000100;
        
        int res=9999999;
        
        while(l<=r){
            memset(seen, false, sizeof(seen));
            
            int m = (l+r)/2;
            
            if(test(0,0,m)){
                res = m;
                r=m-1;
            }else{
                l=m+1;
            }
            
        }
        
        return res;
    }
};