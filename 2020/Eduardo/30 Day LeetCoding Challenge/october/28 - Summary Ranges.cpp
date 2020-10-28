class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        
        vector<string> res;
        
        if(n == 0) return res;
        int l=nums[0];
        
        
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]+1){
                if(l != nums[i-1])res.push_back(to_string(l) + "->" + to_string(nums[i-1]));
                else res.push_back(to_string(l));
                
                l = nums[i];
            }
        }
        
        
       if(l != nums[n-1]) res.push_back(to_string(l) + "->" + to_string(nums[n-1]));
       else res.push_back(to_string(nums[n-1]));
        
        return res;
    }
};