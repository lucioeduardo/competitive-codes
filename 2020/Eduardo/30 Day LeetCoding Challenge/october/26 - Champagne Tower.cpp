#include <algorithm>

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n = query_row;
        double glasses[n+3][n+3];
        
        memset(glasses,0,sizeof(glasses));
        
        glasses[1][1] = poured;
        
        
        
        for(int i=2; i<=n+1; i++){
            for(int j=1; j<=i; j++){
                double a = max(0.0,glasses[i-1][j-1]-1);
                double b = max(0.0,glasses[i-1][j]-1);
                
                glasses[i][j] = 0.5*(a+b);
            }
        }
        
        return min(1.0,glasses[query_row+1][query_glass+1]);
    }
};