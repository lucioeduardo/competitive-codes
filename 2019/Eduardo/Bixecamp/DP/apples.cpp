#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int n,k;
int price[MAXN];
int dp[MAXN][MAXN][MAXN];

int solve(int idx, int p, int q){
    if(q == 0) return 0;
    if(idx > k || p == 0 || q < 0) return 9999999;
    if(dp[idx][p][q] != -1) return dp[idx][p][q];

    if(price[idx] == -1) return dp[idx][p][q] = solve(idx+1,p,q);

    int with = price[idx] + solve(idx, p-1, q-idx);
    int without = solve(idx+1,p,q);

    return dp[idx][p][q] = min(with,without);
}

int main(){
    int c;
    scanf("%d",&c);

    while(c--){
        scanf("%d %d",&n, &k);
        memset(dp,-1,sizeof(dp));

        for(int i=1;i<=k;i++){
            scanf("%d",&price[i]);
        }

        int res = solve(1,n,k);

        if(res > MAXN*10000)
            printf("-1\n");
        else
            printf("%d\n",solve(1,n,k));
    }

    return 0;
}