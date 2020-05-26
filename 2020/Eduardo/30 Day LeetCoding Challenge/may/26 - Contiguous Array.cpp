class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
      
        if(n == 0) return 0;
        
        int sum[n];
        int res=0;
        
        unordered_map<int,int> first;
        
        first[0]=-1;
        
        sum[0] = (nums[0] ? 1 : -1);
        first[sum[0]]=0;
        
        for(int i=1; i<n; i++){
            sum[i] = sum[i-1] + (nums[i] ? 1 : -1);
                        
            if(first.find(sum[i]) == first.end()){
                first[sum[i]] = i;
            }
            else{
                res = max(res, i-first[sum[i]]);
            }
        }
        
        return res;
    }
};