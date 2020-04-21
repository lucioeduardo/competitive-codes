/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    
    int firstOne(BinaryMatrix &binaryMatrix, int i, int n, int m){
        int left = 0; int dir = m-1;
        int res=m;
        
        while(left <= dir){
            int meio=(left+dir)/2;
            
            if(binaryMatrix.get(i,meio)){
                res = meio;
                dir=meio-1;
            }else{
                left=meio+1;
            }
        }
        
        return res;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int n = dim[0], m = dim[1];
        
        int res=m;
        
        for(int i=0; i<n; i++){
            res = min(res, firstOne(binaryMatrix, i, n, m));
        }
        
        return (res == m) ? -1: res;
    }
};