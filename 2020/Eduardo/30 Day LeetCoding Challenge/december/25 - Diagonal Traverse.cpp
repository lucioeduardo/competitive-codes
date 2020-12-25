class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        if(n == 0) return vector<int>();
        
        int m = matrix[0].size();
        
        int x=0, y=0;
        int sX=-1, sY=1;
        
        vector<int> res;
        
        while(res.size() < n*m){
            res.push_back(matrix[x][y]);
        
            
            bool f = false;
        
            
            if(sX == 1){
                if(x == n-1){
                    f=true;
                    y++;
                }else if(y == 0){
                    f=true;
                    x++;
                }
            }else{
                if(y == m-1){
                    f=true;
                    x++;
                }else if(x == 0){
                    f=true;
                    y++;
                }
            }
            
            if(f){
                sX = -sX;
                sY = -sY;
            }else{
                x += sX;
                y += sY;
            }
        }
        
        return res;

    }
    
};