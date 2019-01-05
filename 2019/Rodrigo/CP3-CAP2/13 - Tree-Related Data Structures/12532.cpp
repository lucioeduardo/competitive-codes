#include <bits/stdc++.h>
#define MAXN 100010

int v[MAXN];
int st[3 * MAXN];

int check(int x) { return x > 0 ? 1 : x ? -1 : 0; }

void build(int node, int L, int R)
{
	if(L ^ R) {

		int mid = (L + R) >> 1;
		int l = node << 1;
		int r = l + 1;

		build(l, L, mid);
		build(r, mid + 1, R);

		st[node] = st[l] * st[r];

	} else{
		st[node] = check(v[L]);
	}
}

void update(int node, int L, int R, int ind, int value)
{
	if(R < ind || L > ind)
		return;

	if(L ^ R) {
		int mid = (L + R) >> 1;
		int l = node << 1;
		int r = l +1;

		update(l, L, mid, ind, value);
		update(r, mid+1, R, ind, value);

		st[node] = st[l] * st[r];
	} else {
		st[node] = check(value);
	}
}

int query(int node, int L, int R, int i, int j)
{
	if(i > R || j < L) return 1;
	if(L >= i && R <= j) return st[node];

	int mid = (L + R) >> 1;
	int l = node << 1;
	int r = l + 1;

	return query(l, L, mid, i, j) * query(r, mid + 1, R, i, j);
}

int main()
{
	int N, Q;

	while(scanf("%d %d", &N, &Q) != EOF)
	{
		for(int i=1; i<=N; ++i)
			scanf("%d ", v + i);

		build(1, 1, N);

		while(Q--) {
			char op; int i, j;
			scanf("%c %d %d ", &op, &i, &j);

			if(op == 'P') {
				int answer = query(1, 1, N, i, j);
				printf("%c", answer > 0 ? '+' : answer ? '-' : '0');
			} else {
				update(1, 1, N, i, j);
			}
		}
		printf("\n");

	}

	return 0;
}