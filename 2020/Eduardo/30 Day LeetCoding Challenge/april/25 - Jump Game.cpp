// DP
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool dp[n];
        
        dp[n-1] = true;
        
        for(int i=n-2; i>=0; i--){
            int v = nums[i];
            dp[i] = false; 
            for(int j=1; j<=v && (i+j < n); j++){
                if(dp[i+j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};

// Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int left = n-1;
        
        for(int i=n-2; i>=0; i--){
            if(i + nums[i] >= left)
                left = i;
        }
        
        return !left;
    }
};