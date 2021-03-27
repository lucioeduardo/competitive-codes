class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        bool dp[n+1][n+1];
        
        memset(dp, false, sizeof(dp));
        
        int res=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int r = i+j;
                if(r >= n) break;
                
                if(j == r) dp[j][r]=true;
                else{                    
                    if(j == r-1) dp[j][r] = (s[j] == s[r]);
                    else dp[j][r] =(dp[j+1][r-1] && (s[j] == s[r]));
                }
                
                if(dp[j][r]) res++;
            }    
        }
        
        return res;
    }
};