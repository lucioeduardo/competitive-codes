#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;

ll dp[MAXN][2]; //0 - Nao inverte, 1- inverte
string words[MAXN];
ll cost[MAXN];
int n;

ll solve(int idx, int inverted){
	if(idx > n) return 0;
	if(dp[idx][inverted] != -2) return dp[idx][inverted];

	string act = words[idx];
	string prev = words[idx-1];

	if(inverted) reverse(prev.begin(),prev.end());

	ll norm = -1, inv = -1;

	if(act >= prev)
		norm = solve(idx+1, 0);
	
	reverse(act.begin(), act.end());

	if(act >= prev){
		inv = solve(idx+1,1);
		if(inv != -1) inv += cost[idx];
	}

	if(norm == -1) return dp[idx][inverted] = inv;
	if(inv == -1) return dp[idx][inverted] = norm;
	return dp[idx][inverted] = min(norm,inv);

}

int main(){

	scanf("%d",&n);

	for(int i=1; i<=n; i++){
		scanf("%lld",&cost[i]);
	}

	words[0] = "a";
	for(int i=1; i<=n; i++){
		dp[i][0] = dp[i][1] = -2;
		cin>>words[i];
	}

	printf("%lld\n",solve(1,0));

	return 0;
}
