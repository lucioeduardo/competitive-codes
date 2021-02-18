class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        
        int res=0;
        
        for(int i=0; i<n-2; i++){
            int r = A[i+1]-A[i];
            int q=2;
            
            for(int j=i+2; j<n; j++){
                if(A[j] - A[j-1] == r) q++;
                else break;
                
                if(q > 2) res++;
            }
        }
        
        return res;
    }
};