class Solution {
public:
    vector<int> days, costs;
    int dp[400][1010];
    
    int solve(int idx, int c){        
        if(idx >= days.size())
            return 0;
        if(c >= days[idx])
            return solve(idx+1,c);
        if(dp[idx][c] != -1) return dp[idx][c];
        
        int v = days[idx];
        
        int buy1 = costs[0]+solve(idx+1,v);
        int buy7 = costs[1]+solve(idx+1,v+6);
        int buy30 = costs[2]+solve(idx+1,v+29);
        
        int res = min(buy1, min(buy7, buy30));
                  
        return dp[idx][c] = res;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0, 0);
    }
};