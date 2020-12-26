class Solution {
public:
    
    int n;
    int dp[110];
    
    int solve(string &s, int idx){
        if(s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        
        if(s.length()-idx < 3){
            int v = stoi(s.substr(idx));   
            if(v > 20 && v%10 == 0) return 0;
            return (v > 10 && v <= 26 && v%10) ? 2 : 1;
        }
        
        int v = stoi(s.substr(idx,2));
        
        int res=0;
        
        if(v >= 10 && v <= 26)
            res += solve(s,idx+2);
        
        res += solve(s,idx+1);
        
        return dp[idx] = res;
    }
    
    
    int numDecodings(string s) {
        n = s.length();
        
        for(int i=0; i<n; i++){
            dp[i]=-1;
        }
        
        return solve(s,0);
    }
};