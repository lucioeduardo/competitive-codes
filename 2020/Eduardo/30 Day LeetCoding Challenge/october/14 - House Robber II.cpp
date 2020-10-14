#define MAXN 105

int dp[MAXN][2][2];

class Solution {
public:
    
    vector<int> nums;
    int n;
    
    int solve(int idx, bool l, bool f){        
        if(idx == n-1)
            return (f || l ? 0 : nums[idx]);
        
        if(dp[idx][l][f] != -1) return dp[idx][l][f];

        int out = solve(idx+1,false,f);
        int in = 0;
        
        if(!l) in = nums[idx] + solve(idx+1,true, idx == 0 ? true : f);
                
        return dp[idx][l][f] = max(in,out);
    }
    
    int rob(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        
        memset(dp,-1,sizeof(dp));
        return solve(0,false,false);
    }
};