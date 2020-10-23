class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        int min_v[n];
        min_v[0] = nums[0];
        
        for(int i=1; i<n; i++) min_v[i] = min(nums[i], min_v[i-1]);
        
        stack<int> s;
        
        for(int i=n-1; i>0; i--){
            int v = nums[i];
            
            while(!s.empty() && s.top() <= min_v[i-1]) s.pop();
            if(!s.empty() && s.top() < v) return true;
            
            s.push(v);
        }
        
        return false;
    }
};