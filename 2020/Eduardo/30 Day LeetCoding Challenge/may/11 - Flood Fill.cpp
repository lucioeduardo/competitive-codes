class Solution {
public:
    int sX[4] = {1,-1,0,0};
    int sY[4] = {0,0,1,-1};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        
        if(newColor == color) return image;
        
        image[sr][sc]=newColor;
        
        int n = image.size();
        int m = image[0].size();
        
        for(int i=0; i<4; i++){
            int nX = sr+sX[i];
            int nY = sc+sY[i];
            
            if(isValid(nX,nY,n,m) && color == image[nX][nY]){
                floodFill(image,nX,nY,newColor);
            }
        }
        
        return image;
    }
    
    bool isValid(int x, int y, int n, int m){
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        return true;
    }
};