#include <bits/stdc++.h>
#define MAXN 2020
using namespace std;

int value[MAXN], weight[MAXN];
int S, N;
int dp[MAXN][MAXN];

int solve(int idx, int w){
    if(dp[idx][w] != -1) return dp[idx][w];
    if(idx >= N) return 0;

    int with=0, without=0;

    if(weight[idx] <= w)
        with = value[idx] + solve(idx+1, w-weight[idx]);
    without = solve(idx+1,w);

    return dp[idx][w] = max(with,without);
}

int main(){

    scanf("%d %d", &S, &N);
    memset(dp,-1,sizeof(dp));
    
    for(int i=0; i<N; i++){
        scanf("%d %d", &weight[i],&value[i]);
    }

    printf("%d\n",solve(0,S));

    return 0;
}