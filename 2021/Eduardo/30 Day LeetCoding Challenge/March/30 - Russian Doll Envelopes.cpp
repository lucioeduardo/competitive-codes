bool compare(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}


class Solution {
public:
    vector<vector<int>> envelopes;
    int dp[5050];
    
    int solve(int idx){
        int n = envelopes.size();
        
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int res=1;
        
        for(int i=idx+1; i<n;i++){
            if(envelopes[i][0] > envelopes[idx][0] &&  envelopes[i][1] > envelopes[idx][1])
                res = max(res, 1+solve(i));
        }
        
        return dp[idx]=res;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        this->envelopes=envelopes;
        
        memset(dp,-1,sizeof(dp));
        
        int res=0;
        for(int i=0; i<envelopes.size(); i++)
            res = max(res, solve(i));
        
        return res;
    }
};