class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        
        sort(A.begin(), A.end());
        
        int res = A[n-1]-A[0];
        
        int a = A[0]+K;
        int b = A[n-1]-K;
        
        
        
        for(int i=0; i<n-1; i++){
            int max_v = max(A[i]+K, b);
            int min_v = min(A[i+1]-K, a);
            
            res = min(res, max_v - min_v);
        }
        
        return res;
    }
};