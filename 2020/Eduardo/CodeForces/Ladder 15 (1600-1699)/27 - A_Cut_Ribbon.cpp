#include<bits/stdc++.h>
#define MAXN 4010
using namespace std;

int dp[MAXN];

int main(){
  int n,a,b,c;

  cin>>n>>a>>b>>c;
  
  for(int i=0; i<=n; i++) dp[i]=-999999999;

  dp[n] = 0;

  for(int i=n; i>=0; i--){
    if(i+a <= n) dp[i] = max(dp[i], 1 + dp[i+a]);
    if(i+b <= n) dp[i] = max(dp[i], 1 + dp[i+b]);
    if(i+c <= n) dp[i] = max(dp[i], 1 + dp[i+c]);
  }

  cout << dp[0] << endl;

  return 0;
}