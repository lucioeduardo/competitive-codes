class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size();
        
        int sum[n][m];
        
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                sum[i][j] = matrix[i][j];
                                
                if(i > 0) sum[i][j] += sum[i-1][j];
                if(j > 0) sum[i][j] += sum[i][j-1];
                if(i>0 && j>0) sum[i][j] -= sum[i-1][j-1];
            }
        }
        
        int res=0;
        
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                for(int k=0; k<n; k++){
                    int nX = i+k;
                    int nY = j+k;
                    
                    if(nX >= n || nY >= m) break;
                    
                    int v = sum[nX][nY];
                    
                    if(i>0) v -= sum[i-1][nY];
                    if(j>0) v -= sum[nX][j-1];
                    if(i>0 && j>0) v += sum[i-1][j-1];
                    
                    
                    if(v == (k+1)*(k+1)){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};