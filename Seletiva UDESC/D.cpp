#include <bits/stdc++.h>
#define MAXN 210
using namespace std;

int n, dp[MAXN][MAXN];
float w[MAXN];
float c[MAXN];

int solve(int i, int j)
{
	if(i > n or j > n)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int op1 = (j == 0 or (w[i] > w[j] && c[i] < c[j])) ? 1 + solve(i + 1, i) : 0;
	int op2 = solve(i + 1, j);

	return dp[i][j] = max(op1, op2);
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		for(int i=1; i<=n; ++i)
			scanf("%f %f", &w[i], &c[i]);

		for(int i=0; i<=n; ++i)
			for(int j=0; j<=n; ++j)
				dp[i][j] = -1;

		printf("%d\n", solve(1, 0));
	}
	return 0;
}