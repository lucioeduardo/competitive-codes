class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=0;
        
        for(int num: nums){
            sum += num;
        }
        
        int at=0, target = sum-x;
        int l=0;
        int res=-1;
        
        for(int i=0; i<nums.size(); i++){
            while(at + nums[i] > target && l <= i){
                at -= nums[l++];
            }
            
            at += nums[i];
            
            if(at == target)
                res = max(res, i-l+1);
        }
        
        return res == -1 ? -1 : nums.size()-res;
    }
};