// https://www.urionlinejudge.com.br/judge/pt/problems/view/1474

#include <bits/stdc++.h>
#define MOD 1000000
#define MAX 2
#define ll unsigned long long
using namespace std;

ll ans[MAX][MAX], curr[MAX][MAX];
ll n, k, l;

void mult(ll a[MAX][MAX], ll b[MAX][MAX]) {

	for(int i=0; i<MAX; ++i)
		for(int j=0; j<MAX; ++j) {
			curr[i][j] = 0;
			for(int k=0; k<MAX; ++k)
				curr[i][j] = (curr[i][j] + (((a[i][k]%MOD) * (b[k][j]%MOD) % MOD))) % MOD;
		}

	memcpy(a, curr, sizeof curr);
}

void fast_exp(ll a[MAX][MAX], ll e) {
	while(e) {
		if(e&1LL)
			mult(ans, a);

		mult(a, a);
		e >>= 1LL;
	}
}

ll factorial(ll x) {
	ll answer = x;

	while(--x)
		answer = (answer * x) %MOD;

	return answer;
}

ll mod_pow(ll b, ll e) {
	ll answer = 1LL;

	while(e) {
		if(e&1)
			answer = (answer * b) % MOD;

		b = (b*b) % MOD;
		e >>= 1LL;
	}

	return answer;
}

int main()
{
	while(scanf("%llu %llu %llu", &n, &k, &l) != EOF) {
		k %= MOD;
		l %= MOD;

		ans[0][0] = ans[1][1] = 1;
		ans[1][0] = ans[0][1] = 0;

		ll m[MAX][MAX] = {{0,1}, {l,k}};

		fast_exp(m, n/5 -1);

		m[0][0] = 1; m[0][1] = 0;
		m[1][0] = k; m[1][1] = 0;

		mult(ans, m);

		// for(int i=0; i<MAX; ++i) {
		// 	for(int j=0; j<MAX; ++j)	
		// 		printf("%llu ", ans[i][j]);
		// 	printf("\n");
		// }
		printf("%06lld\n", ans[1][0]);
	}
}