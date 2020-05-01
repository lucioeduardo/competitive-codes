class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(!n) return 0;
        
        int m = matrix[0].size();
        
        int res[n][m];
        int maxSq=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!i || !j){
                    res[i][j] = (matrix[i][j] == '1');
                }else{
                    if(matrix[i][j] == '1') res[i][j] = min(res[i][j-1], min(res[i-1][j-1], res[i-1][j]))+1;
                    else res[i][j] = 0;
                }
            
                maxSq = max(maxSq, res[i][j]);
            }
        }
        
        return maxSq*maxSq;
    }
};