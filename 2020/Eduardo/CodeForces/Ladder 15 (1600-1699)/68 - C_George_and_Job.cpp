#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 5050
using namespace std;

int n,m;
int v[MAXN];
ll sum[MAXN];

ll dp[MAXN][MAXN];

ll solve(int idx, int k){
  if(k == 0) return 0;
  if(idx >= n) return 0;
  if(dp[idx][k] != -1) return dp[idx][k];

  ll sem = solve(idx+1,k);
  ll com = 0;

  for(int i=1;i<=m && idx+i<=n; i++){
    com = max(com, sum[idx+i]-sum[idx] + solve(idx+i,k-1));
  }

  //cout << idx << " " << k << " " << max(com,sem) << endl;
  return dp[idx][k] = max(com,sem);
}

int main(){
  int k;

  cin>>n>>m>>k;

  sum[0]=0;

  init(dp,-1);

  for(int i=0; i<n; i++){
    cin>>v[i];
    if(i>0) sum[i] = sum[i-1] + v[i-1];
  }

  sum[n] = sum[n-1] + v[n-1];

  cout << solve(0,k);
  
  return 0;
}