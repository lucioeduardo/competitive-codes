class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int l=0, n = nums.size();
        int r = n-k;
                
        for(int i=0; i<n; i++){
            while(!res.empty() && r > 0 && nums[i] < res[res.size()-1]){
                r--;
                res.pop_back();
            }
            
            res.push_back(nums[i]);
        }
        
        while(r > 0){
            r--;
            res.pop_back();
        }
            
        
        return res;
    }
};