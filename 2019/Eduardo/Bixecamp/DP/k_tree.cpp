#include <bits/stdc++.h>
#define MAXK 110
#define M 1000000007
#define ll long long
using namespace std;

ll dp[MAXK][2], k, d;

ll solve(int n, int d_esc){
	if(n < 0) return 0;
	if(n == 0) return d_esc;
	if(dp[n][d_esc] != -1) return dp[n][d_esc];
	
	ll res = 0;

	for(int i=1; i<=k; i++){
		res = (res + solve(n-i, d_esc || i >= d) )%M;
	}

	return dp[n][d_esc] = res;
}

int main(){
	int n;

	//printf("%d",M);

	scanf("%d %d %d",&n,&k,&d);

	memset(dp,-1,sizeof(dp));
	printf("%lld\n", solve(n,0));

	return 0;
}
