class Solution {
public:
    
    int kadane(vector<int>& A){
        int res=A[0];
        int sum=0;
        
        for(int num: A){
            sum += num;
            res = max(sum, res);
            
            if(sum < 0) sum=0;
        }
        
        return res;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int sum_all=0;
        int max_normal = kadane(A);
                
        for(int i=0; i<A.size(); i++){
            sum_all += A[i];
                        
            A[i]=-A[i];
        }
        
        if(max_normal < 0) return max_normal;
        
        int max_inv = kadane(A);
        return max(max_normal, sum_all + max(max_inv,0));
    }
};