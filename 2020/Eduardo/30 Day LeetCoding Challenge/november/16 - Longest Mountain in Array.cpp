class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() < 3) return 0;
        
        bool f = A[1] > A[0];
        int act = 1, prev=0;
        int res=0;
        
        for(int i=2; i<A.size(); i++){
            bool x = A[i] > A[i-1];
            
            if(A[i] == A[i-1]){
                act=0;
                continue;
            }
            
            if(x == f){
                act++;
            }else{
                prev=act;
                act=1;
                f = !f;
            }
            
            if(act && prev && !f) res = max(res, act+prev+1);
        }
        
        return res;
    }
};