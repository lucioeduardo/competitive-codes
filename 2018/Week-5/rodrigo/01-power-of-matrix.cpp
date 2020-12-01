// https://www.spoj.com/problems/MPOW/

#include <bits/stdc++.h>
#define MAX 52
#define MOD 1000000007
#define ll long long
using namespace std;

int k, size, n;
ll curr[MAX][MAX], ans[MAX][MAX], m[MAX][MAX];

void mult(ll m1[MAX][MAX], ll m2[MAX][MAX])
{
	for(int i=0; i<size; ++i) {
		for(int j=0; j<size; ++j) {
			curr[i][j] = 0;
			for(int k=0; k<size; ++k)
				curr[i][j] = (curr[i][j] + ((m1[i][k] * m2[k][j]) % MOD)) % MOD;
		}
	}

	memcpy(m1, curr, sizeof curr);
}

void fast_exp(ll m[MAX][MAX], int e) {

	while(e) {
		if(e%2)
			mult(ans, m);

		mult(m, m);
		e /= 2;
	}
}

int main()
{
	scanf("%d", &k);

	while(k--) {
		scanf("%d %d", &size, &n);

		for(int i=0; i<size; ++i) {
			for(int j=0; j<size; ++j) {
				scanf("%d", &m[i][j]);
				ans[i][j] = (i == j);
			}
		}
		
		fast_exp(m, n);

		for(int i=0; i<size; ++i) {
			for(int j=0; j<size; ++j){
				if(j != (size-1)) printf("%lld ", ans[i][j]);
				else printf("%lld\n", ans[i][j]);
			}
		}
	}
	return 0;
}
