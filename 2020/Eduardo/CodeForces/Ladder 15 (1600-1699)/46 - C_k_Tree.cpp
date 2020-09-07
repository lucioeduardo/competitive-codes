#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

ll dp[MAXN][2];
int n,k,d;

ll solve(int x, int f){
  if(x == 0 && f) return 1;
  if(x <= 0) return 0;

  if(dp[x][f] != -1) return dp[x][f];

  ll res=0;

  for(int i=1; i<=k; i++){
    res = (res + solve(x-i,f || i >= d)) % MOD;
  }

  return dp[x][f] = res;
}


int main(){

  cin>>n>>k>>d;

  init(dp,-1);  

  cout << solve(n,false);

  return 0;
}