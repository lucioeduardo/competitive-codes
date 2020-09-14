#define MAXN 110

int dp[MAXN][2];

class Solution {
public:
    int n;
    vector<int> nums;
    
    int solve(int idx, bool f){
        if(idx >= n) return 0;
        if(dp[idx][f] != -1) return dp[idx][f];
        
        int com=0, sem=0;
        if(!f) com = nums[idx] + solve(idx+1, true);
        sem = solve(idx+1,false);
        
        return dp[idx][f] = max(com,sem);
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,false);
    }
};