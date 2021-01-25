class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int l = -n*2;
        
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                if(i-l-1 < k)
                    return false;
                
                l = i;
            }
        }
        
        return true;
    }
};