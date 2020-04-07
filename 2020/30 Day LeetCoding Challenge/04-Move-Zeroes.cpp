class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int firstZero=-1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0 && firstZero != -1){
                swap(nums[i],nums[firstZero]);
                firstZero++;
            }
            if(nums[i] == 0){
                if(firstZero == -1) firstZero = i;
            }
        }
    }
};