#define MAXN 110

class Solution {
public:
    int dp[MAXN][MAXN];
    vector< pair<int,int> > graph[MAXN];
    
    int solve(int src, int dest, int k){
        if(src == dest) return 0;
        if(k == 0) return 999999999;
        if(dp[src][k] != -1) return dp[src][k];
        
        int res = 999999999;
        
        for(int i=0; i<graph[src].size(); i++){
            int v = graph[src][i].first, w = graph[src][i].second;
            
            res = min(res, w + solve(v,dest,k-1));
        }
        
        return dp[src][k] = res;
    }
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        memset(dp,-1,sizeof(dp));
        
        for(vector<int> vec: flights){
            int u=vec[0],v=vec[1],w=vec[2];
            
            graph[u].push_back({v,w});
        }
        
        int res = solve(src,dst,K+1);
        
        return res >= 999999999 ? -1 : res;
    }
};