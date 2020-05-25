#define MAXV 2010
#define MAXN 505

int dp[MAXN][MAXV];

class Solution {
public:
    vector<int> pos[MAXV];
    
    int solve(int idx, int min, vector<int>& A, vector<int>& B){
        if(idx >= A.size()) return 0;
        if(dp[idx][min] != -1) return dp[idx][min];
        
        int v = A[idx];
        
        int res = solve(idx+1,min,A,B);
        
        
        int u=-1;
        for(int i=0; i <pos[v].size(); i++){
            if(pos[v][i]>=min){
                u=i;
                break;
            }
        }
        
        if(u != -1){
            int m = pos[v][u];
            pos[v][u]=-1;
            res = max(res, 1+solve(idx+1,m+1,A,B));
            pos[v][u]=m;           
        }
        
        
        return dp[idx][min]=res;
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        for(int i=0; i<B.size(); i++){
            pos[B[i]].push_back(i);
        }
        
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<MAXV; j++){
                dp[i][j]=-1;
            }
        }
        
        return solve(0,0,A,B);
    }
};