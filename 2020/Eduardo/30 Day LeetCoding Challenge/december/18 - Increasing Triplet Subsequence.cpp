class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        int mins[3];
        
        int it=1;
        
        mins[0] = nums[0];
        
        for(int i=1; i<n; i++){
            
            for(int j=0; j<3; j++){                
                if(j == it){
                    mins[it++] = nums[i];
                    break;
                }
                if(nums[i] <= mins[j] || j == it){
                    mins[j] = nums[i];
                    break;
                }
            }
            
            if(it == 3) return true;
        }
        
        return false;
    }
};