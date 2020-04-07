class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int at=nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(at < 0) at=0;
            at += nums[i];
            res = max(res, at);
        }
        
        return res;
    }
};