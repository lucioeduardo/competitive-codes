class Solution {
public:
    int test(vector<vector<int>>& A, vector<vector<int>>& B, int x, int y){
        int n = B.size();
        int m = B[0].size();
        
        int res=0;
        
        for(int i=max(0, -x); i<n; i++){
            if(i+x >= n) break;;
            for(int j=max(0, -y); j<m ; j++){
                if(j+y >= n) break;
                
                if(A[i+x][j+y] == B[i][j] && B[i][j])
                    res++;
            }
        }
        
        return res;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = B.size();
        int m = B[0].size();        
        
        int res=0;
        
        for(int i=-n; i<=n; i++){
            for(int j=-m; j<=m; j++){
                res = max(res, test(A,B,i,j));
            }
        }
        
        return res;
    }
};