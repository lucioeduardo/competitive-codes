#include<bits/stdc++.h>
#define MAXN 100100
#define ll long long
using namespace std;

ll qtd[MAXN], dp[MAXN];

ll solve(int idx){
  if(idx <= 0) return 0;
  if(dp[idx] != -1) return dp[idx];
  return dp[idx] = max(qtd[idx]*idx + solve(idx-2), solve(idx-1));
}

int main(){
  int n;
  ll m=0;

  cin>>n; 

  for(int i=0; i<n; i++){
    ll v;
    cin>>v;

    m = max(m,v);
    qtd[v]++;
  }

  memset(dp,-1,sizeof(dp));

  cout << solve(m) << endl;

  return 0;
}