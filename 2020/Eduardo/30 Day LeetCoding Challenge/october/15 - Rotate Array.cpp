class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return;
        vector<int> res;
        
        k%=n;
        
        int idx=n-k;
        
        for(int i=0; i<n; i++){
            idx %= n;
            res.push_back(nums[idx]);
            idx++;
        }
                
        nums=res;
    }
};