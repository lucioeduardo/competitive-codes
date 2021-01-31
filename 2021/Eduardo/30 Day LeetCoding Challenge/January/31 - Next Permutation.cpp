class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag = false;
        int n = nums.size();
        
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                flag = true;
                
                int j=i+1;
                while(j < n-1 && nums[j+1] > nums[i])
                    j++;
                
                swap(nums[i], nums[j]);
                
                sort(nums.begin()+i+1, nums.end());
                
                break;
            }
        }
        
        if(!flag)
            sort(nums.begin(), nums.end());
    }
};