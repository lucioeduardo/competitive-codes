class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l=0, r=nums.size()-1;
        
        int res=0;
        
        while(l < r){
            while(nums[l] + nums[r] > k && l < r-1)
                r--;
            
            
            if(nums[l] + nums[r] == k){
                res++;
                l++;r--;
            }else{
                l++;
            }
        }
        
        return res;
    }
};