#include <bits/stdc++.h>
#define M 1000000007
#define MAXN 10000010
#define ll long long
using namespace std;

ll dp[MAXN][2];

int main(){
	int n;

	scanf("%d",&n);

	memset(dp,-1,sizeof(dp));


	dp[1][0]=0;
	dp[1][1]=1;

	for(int i=2; i<=n; i++){
		dp[i][0] = (3*dp[i-1][1])%M;
		dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1])%M;
	}

	printf("%lld\n",dp[n][0]);

	return 0;
}
