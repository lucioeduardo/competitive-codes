class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=1, right=nums.size()-1;
        
        nums.push_back(-9999);
        
        while(left <= right){
            
            int mid = (left+right)/2;
            
            
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            
            int v;
            
            if(nums[mid+1] == nums[mid]) v=mid+1;
            else v=mid;
            
            cout << mid << " " << v << endl;
            
            if((v+1)%2 == 0)
                left=mid+1;
            else
                right=mid-1;
        }
        
        return nums[0];
    }
};