class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        int n = nums.size();
        
        int dp[n][n];
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dp[i][j] = 0;
        
        
        for(int i=1; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                int r = j+i+1;
                
                for(int k=j+1;k<r; k++){
                    dp[j][r] = max(dp[j][r], nums[j]*nums[k]*nums[r] + dp[j][k] + dp[k][r]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};