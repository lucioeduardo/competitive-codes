// Recursive Soluton
#define MAXN 1010

int dp[MAXN][MAXN];
string t1,t2;

int solve(int a, int b){
    if(a < 0 || b < 0) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    
    int v = t1[a] == t2[b];
    
    return dp[a][b] = max(v + solve(a-1,b-1), max(solve(a-1,b), solve(a,b-1)));
}


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        t1 = text1;
        t2 = text2;
        
        
        for(int i=0; i<t1.length(); i++)
            for(int j=0; j<t2.length(); j++)
                dp[i][j]=-1;
        
        return solve(t1.length()-1,t2.length()-1);
    }
};

//=====================================================================================

// Interactive
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        int dp[n+2][m+2];
        
        for(int i=0; i<=n; i++) dp[i][m]=0;
        for(int i=0; i<=m; i++) dp[n][i]=0;
                
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int v = text1[i] == text2[j];                
                dp[i][j] = max(v + dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1]));
            }
        }
        
        return dp[0][0];
    }
};
