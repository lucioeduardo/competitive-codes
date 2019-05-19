#include <bits/stdc++.h>
#define MAXN 4040
using namespace std;

int n,a,b,c;
int dp[MAXN];

int solve(int n){
	if(n == 0) return 0;
	if(n < 0) return -999999;
	if(dp[n] != -1) return dp[n];

	return dp[n] = 1 + max(solve(n-a),max(solve(n-b),solve(n-c)));
}

int main(){
	
	memset(dp,-1,sizeof(dp));
	scanf("%d %d %d %d\n",&n,&a,&b,&c);

	printf("%d\n",solve(n));

	return 0;
}
