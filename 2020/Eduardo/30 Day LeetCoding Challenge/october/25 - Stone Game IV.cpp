class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[n+1];
        for(int i=0; i<=n; i++) dp[i]=false;
        
        vector<int> squares;
        for(int i=1; i*i <= n; i++){
            squares.push_back(i*i);
            dp[i*i]=true;
        }
        
        for(int i=2; i<=n; i++){
            if(dp[i]) continue;
            
            for(int j=1; j*j < i && !dp[i]; j++){
                if(!dp[i-j*j]) dp[i]=true;
            }
            
        }
        
        return dp[n];
    }
};