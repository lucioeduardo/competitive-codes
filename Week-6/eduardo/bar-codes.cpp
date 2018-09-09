#include <cstdio>
#define MAXN 55
#define ll long long

ll dp[MAXN][MAXN], n, m, k;

ll solve(ll soma, int i){
	if(soma == n && i == k)
		return 1;
	if(soma > n)
		return 0;
	if(i > k)
		return 0;
	if(dp[soma][i] != -1)
		return dp[soma][i];
		
	ll res = 0;
	for(int j=1; j<=m; j++){
		res += solve(soma+j, i+1);
	}
	return dp[soma][i] = res;
	
}

int main(){
	
	while(scanf("%lld %lld %lld",&n,&k,&m) != EOF){
		for(int i=0; i<MAXN; i++)
			for(int j=0; j<MAXN; j++)
				dp[i][j]=-1;
		
		printf("%lld\n", solve(0,0));
	}
}
