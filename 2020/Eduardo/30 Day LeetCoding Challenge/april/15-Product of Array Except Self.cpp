class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> output;
        int p_left[n+1], p_right[n+1];
        
        
        output.push_back(1);
        
        for(int i=1; i<n; i++){
            output.push_back(output[i-1]*nums[i-1]);
        }
        
        int v=1;
        
        for(int i=n-2; i>=0; i--){
            output[i] = output[i]*(nums[i+1]*v);
            
            v *= nums[i+1]; 
        }
        
        
        return output;
    }
};