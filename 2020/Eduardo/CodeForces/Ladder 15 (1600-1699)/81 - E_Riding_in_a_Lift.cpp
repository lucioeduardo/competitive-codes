#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 5010
using namespace std;

ll dp[MAXN], sum[MAXN];

int main(){
  int n,a,b,k;

  cin>>n>>a>>b>>k;

  for(int i=0;i<=n;i++) dp[i]=1;

  for(int i=0; i<k; i++){
    sum[0]=0;

    for(int j=1; j<=n; j++)
      sum[j] = (dp[j] + sum[j-1])%MOD;
  
    for(int j=1; j<=n; j++){
      int d = abs(b-j);

      dp[j] = (sum[min(n,j+d-1)] - sum[max(1,j-d+1)-1] - dp[j] + 4LL*MOD)%MOD;
    }
  }

  cout << dp[a] << endl;

  return 0;
}