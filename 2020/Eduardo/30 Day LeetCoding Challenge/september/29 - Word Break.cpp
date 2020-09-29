class Solution {
public:
    int n;
    vector<string> dict;
    string s;
    
    bool solve(int idx, vector<int>& dp){
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];
        bool res=false;
        
        for(int i=0; i<dict.size(); i++){
            int k = dict[i].length();
            if(dict[i] == s.substr(idx,k))
                res = res || solve(idx+k,dp);
        }
        
        return dp[idx]=res;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
       n = s.length();
       this->s = s;
       dict = wordDict;
       vector<int> dp(n,-1); 
        
       return solve(0,dp);
    }
};