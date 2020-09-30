class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        
        for(int i=0; i<nums.size();i++){
            int v = nums[i];
            
            while(v >= 1 && v < nums.size()){
                //cout << v << " " << nums[v-1] << endl;
                
                if(v == nums[v-1]) break;    
                swap(nums[i],nums[v-1]);
                v = nums[i];
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            //cout << nums[i] << endl;
            if(nums[i] != i+1) return i+1;
        }
        
        return nums.size()+1;
    }
};