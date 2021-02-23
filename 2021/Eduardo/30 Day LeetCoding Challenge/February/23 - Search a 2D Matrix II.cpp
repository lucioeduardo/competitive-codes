class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int mr=m-1;
        
        for(int i=0; i<n; i++){
            int l=0, r=mr;
            
            while(l <= r){
                int m = (l+r)/2;
                
                if(matrix[i][m] < target){
                    l = m+1;
                }else if(matrix[i][m] == target){
                    return true;
                }else{
                    r=m-1;   
                }
            }
            
            mr = r;
        }
        
        return false;
    }
};