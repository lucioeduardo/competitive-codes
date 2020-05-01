class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int sum[len+1], res=0;
        
        sum[0] = 0;
        for(int i=0; i<nums.size(); i++){
            sum[i+1] = sum[i] + nums[i];
        }
        
        unordered_map<int,int> cache;
        
        for(int i=0; i<=len; i++){            
            if(cache.count(sum[i]-k))
                res += cache[sum[i]-k];
            
            cache[sum[i]]++;
        }
        
        return res;
    }
};