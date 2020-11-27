#define MAXN 210
#define MAXV 110

int dp[MAXN][MAXN*MAXV];

class Solution {
public:
    vector<int> nums;
    
    
    bool solve(int idx, int sum){
        if(sum == 0) return true;
        if(sum < 0 || idx >= nums.size()) return false;
        if(dp[idx][sum] != -1) return dp[idx][sum];
    
        return dp[idx][sum] = solve(idx+1,sum) || solve(idx+1, sum-nums[idx]);
    }
    
    bool canPartition(vector<int>& nums) {
        this->nums = nums;
        
        int sum=0;
        
        memset(dp,-1,sizeof(dp));
        
        for(int num: nums){
            sum += num;
        }
        
        if(sum % 2) return false;
            
        return solve(0,sum/2);
    }
};