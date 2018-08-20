// https://uva.onlinejudge.org/external/124/p12470.pdf

#include <bits/stdc++.h>
#define MAX 3
#define MOD 1000000009
#define ll unsigned long long
using namespace std;

ll n;
ll curr[MAX][MAX], ans[MAX][MAX];

void mult(ll a[MAX][MAX], ll b[MAX][MAX])
{
	for(int i=0; i<MAX; ++i) {
		for(int j=0; j<MAX; ++j) {
			curr[i][j] = 0;
			for(int k=0; k<MAX; ++k)
				curr[i][j] = (curr[i][j] + ((a[i][k] * b[k][j]) % MOD)) % MOD;
		}
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

int main()
{
	while((cin >> n) && n)
	{
		for(int i=0; i<MAX; ++i)
			for(int j=0; j<MAX; ++j)
				ans[i][j] = (i == j);

		ll m[MAX][MAX] = {{0,1,0}, {0,0,1}, {1,1,1}};

		fast_exp(m, n);
		cout << ans[1][1] << endl;
	}
	return 0;
}