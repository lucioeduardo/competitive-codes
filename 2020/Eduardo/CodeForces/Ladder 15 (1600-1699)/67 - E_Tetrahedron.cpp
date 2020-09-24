#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 10000010
using namespace std;

ll dp[MAXN][2];
int n;

int main(){  
  cin>>n;

  dp[n][0]=1;
  dp[n][1]=0;

  for(int i=n-1; i>=0; i--){
    dp[i][1] = (3*dp[i+1][0])%MOD;
    dp[i][0] = (2*dp[i+1][0] + dp[i+1][1])%MOD; 
  }

  cout << dp[1][1] << endl;

  return 0;
}