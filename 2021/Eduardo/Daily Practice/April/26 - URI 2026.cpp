#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
#define MAXW 1010
using namespace std;

int dp[MAXN][MAXW], e[MAXN], pc[MAXN];
int n;

int solve(int idx, int w){
  if(idx >= n) return 0;
  if(dp[idx][w] != -1) return dp[idx][w];
  int res=0;

  if(w >= pc[idx])
    res = max(res, e[idx] + solve(idx+1, w-pc[idx]));
  
  res = max(res, solve(idx+1,w));

  return dp[idx][w] = res;
}

int main(){
  int t;

  cin>>t;

  for(int i=1; i<=t; i++){
    int w;

    cin>>n>>w;

    memset(dp,-1,sizeof(dp));

    for(int j=0;j<n;j++){
      cin>>e[j]>>pc[j];
    }

    printf("Galho %d:\n",i);
    printf("Numero total de enfeites: %d\n\n", solve(0,w));
  }
  
  return 0;
}