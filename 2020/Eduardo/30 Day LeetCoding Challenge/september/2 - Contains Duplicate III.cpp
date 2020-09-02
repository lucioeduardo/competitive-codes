class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<long long> v;
        
        for(int i=1; i<=k && i<n; i++){
            v.insert(nums[i]);
        }
                
        if(n < 2 || k == 0) return false;
        
        for(int i=0; i<n; i++){            
            if(v.size() > min(k, n-i-1))
                v.erase(nums[i]);
            
            if(v.size() == 0) break;
            
            set<long long>::iterator it = v.lower_bound(nums[i]), p = v.end();
            p = prev(it);
                        
            if(it != v.end() && abs(nums[i] - *it) <= t)
                return true;
            
            if(p != v.end() && abs(nums[i] - *p) <= t)
                return true;
       
            
            if(i+k+1 < n) v.insert(nums[i+k+1]);
        
            
        }
        
        return false;
    }
};