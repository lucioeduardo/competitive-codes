class Solution {
public:
    
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        
        int res=0, dir=0;
        long long prod=1;
        
        
        for(int i=0; i<n; i++){
            
            while(dir > i && prod > k){
                prod /= nums[--dir];
            }
            
            while(dir < n && prod < k){
                prod *= nums[dir++];
            }
            
            res += max(0,dir-i-1 + (prod < k));
            prod /= nums[i];
        }
        
        
        return res;
    }
};