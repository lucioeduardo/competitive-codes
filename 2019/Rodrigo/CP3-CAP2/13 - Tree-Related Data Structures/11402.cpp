#include <bits/stdc++.h>
#define value first
#define change second
#define MAXN (1 << 10) * 1001
using namespace std;

char warrior[MAXN];
pair<int, int> st[3 * MAXN];

void build(int node, int L, int R)
{
	if(L ^ R) {
		int mid = (L + R) / 2;
		int l = 2 * node;
		int r = 2 * node + 1;

		build(l, L, mid);
		build(r, mid + 1, R);

		st[node].value = st[l].value + st[r].value;
		st[node].change = 2;

	} else {
		st[node].value = warrior[L] - '0';
		st[node].change = 2;
	}
}

void check(int node, int change) {
	if(change == -1 && st[node].change == -1)
		change = 2;
	st[node].change = change;
}

void calc(int node, int size, int change)
{
	if(change == 0)
		st[node].value = 0;
	else if(change == 1)
		st[node].value = size;
	else if(change == -1)
		st[node].value = size - st[node].value;

	if(size > 1){
		check(2 * node, change);
		check(2 * node + 1, change);
	}

	st[node].change = 2;
}

void update(int node, int L, int R, int i, int j, int change)
{
	if(L > j || R < i)
		return;

	if(L == R) {
		check(node, change);
		calc(node, 1, st[node].change);

	} else {

		int mid = (L + R) / 2;
		int l = 2 * node;
		int r = 2 * node + 1;

		build(l, L, mid);
		build(r, mid + 1, R);

		if(L >= i && R <= j) {
			check(node, change);
			calc(node, (R - L) + 1, change);
		}
	}
}

pair<int, int> query(int node, int L, int R, int i, int j)
{
	if(i > R || j < L)
		return {0, 2};

	if(L >= i && R <= j) {
		if(st[node].change != 2)
			calc(node, (R - L) + 1, st[node].change);
		return st[node];

	} else {

		int mid = (L + R) / 2;
		int l = 2 * node;
		int r = 2 * node + 1;

		if(st[node].change != 2)
			calc(node, (R - L) + 1, st[node].change);

		auto lside = query(l, L, mid, i, j);
		auto rside = query(r, mid + 1, R, i, j);

		if(lside.change != 2)
			calc(l, (mid - L)  + 1, lside.change);
		if(rside.change != 2)
			calc(r, (R - (mid+1))  + 1, rside.change);

		return {lside.value + rside.value, 2};
	}

}

int main()
{
	int t; scanf("%d", &t);

	for(int i=1; i<=t; ++i)
	{
		int N = 1;
		int n; scanf("%d ", &n);

		strcpy(warrior, "0");

		while(n--)
		{
			int k; scanf("%d ", &k);
			char str[210]; scanf("%s", str);

			while(k--){
				strcpy(warrior + N, str);
				N += strlen(str);
			}
		}

		int q; scanf("%d ", &q);

		build(1, 1, --N);

		printf("Case %d:\n", i);
		int Q = 0;

		while(q--)
		{
			char op; int x, y;
			scanf("%c %d %d ", &op, &x, &y);
			++x, ++y;

			if(op == 'F')
				update(1, 1, N, x, y, 1);
			else if(op == 'E')
				update(1, 1, N, x, y, 0);
			else if(op == 'I')
				update(1, 1, N, x, y, -1);
			else
				printf("Q%d: %d\n", ++Q, query(1, 1, N, x, y).value);
			
		}
	}
	return 0;
} 