class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        bool dp[n+2][n+2];
        
        string res = s.substr(0,1);
        
        for(int i=0; i<n+2; i++)
            for(int j=0; j<n+2; j++)
                dp[i][j]=false;
        
        
        for(int i=0; i<n; i++){
            dp[i][i]=true;
            dp[i][i+1]=s[i] == s[i+1];
        
            if(dp[i][i+1] && res.length() < 2)
                res = s.substr(i,2);
        }
        
        
        for(int j=2;j<n;j++){
            for(int i=0;i+j<n;i++){
                if(s[i] == s[i+j] && dp[i+1][i+j-1]){
                    dp[i][i+j]=true;
                    if(res.length() < j+1)
                        res = s.substr(i,j+1);
                }
            }
        }
        
        return res;
    }
};