class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        
        sort(sorted.begin(), sorted.end());
        
        int l=0, r=nums.size()-1;
        
        while(l < r && nums[l] == sorted[l]) l++;
        while(r > l && nums[r] == sorted[r]) r--;
        
        int res = r-l+1;
        
        return res == 1 ? 0: res;
    }
};