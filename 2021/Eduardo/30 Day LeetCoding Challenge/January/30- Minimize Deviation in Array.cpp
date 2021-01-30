class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> c;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i] % 2)
                c.insert(nums[i]*2);
            else
                c.insert(nums[i]);
        }
        
        int res = *c.rbegin() - *c.begin();
        
        while(true){
            int v = *c.rbegin();
            
            if(v % 2) break;
            
            c.erase(v);
            c.insert(v/2);
            
            res = min(res, *c.rbegin() - *c.begin());
        }
        
        return res;
    }
};