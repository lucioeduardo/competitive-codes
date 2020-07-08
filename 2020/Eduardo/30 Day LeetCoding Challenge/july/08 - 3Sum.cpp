class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> sol;
        
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            
            int l = i+1;
            int r = nums.size()-1;
            
            if(i > 0 && n == nums[i-1]) continue;
            
            while(l < r){
                int v = nums[l] + nums[r] + n;
                
                if(v == 0){
                    bool flag=true;
                    if(sol.size() > 0){
                        vector<int> last = sol.back();
                        if(last[0] == n && last[1] == nums[l] && last[2] == nums[r])
                            flag=false;
                    }
                    
                    if(flag) sol.push_back({n,nums[l],nums[r]});
                    l++;
                    r--;
                    continue;
                }
                
                if(v < 0){
                    l++;
                }else{
                    r--;
                }
            }
            
            
        }
        
        return sol;
    }
    
    
};