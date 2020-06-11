class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0, right = nums.size()-1;
        
        for(int i=0; i<nums.size(); i++){
            
            while(true){
                if(nums[i] == 0 && i > left) {
                    swap(nums[i],nums[left]);
                    left++;
                }
                else if(nums[i] == 2 && i < right) {
                    swap(nums[i],nums[right]);
                    right--;
                }else break;
            }          
        }        
    }
};