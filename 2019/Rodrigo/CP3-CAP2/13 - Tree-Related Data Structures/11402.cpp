#include <bits/stdc++.h>
#define MAXN (1 << 10) * 1001
using namespace std;

typedef struct {
	int value, change;
} segment;

segment st[4 * MAXN];

char warrior[MAXN];

void build(int node, int L, int R)
{
	if(L ^ R) {
		int mid = (L + R) >> 1;

		build(node << 1, L, mid);
		build(node << 1 | 1, mid + 1, R);

		st[node].value = st[node << 1].value + st[node << 1 | 1].value;
		st[node].change = 2; // indicates updated

	} else {
		st[node].value = warrior[L] - '0';
		st[node].change = 2;
	}
}

void check(int node, int change)
{
	if(change == -1 and st[node].change != 2)
		st[node].change = 1 - st[node].change;
	else
		st[node].change = change;
}

void calc(int node, int size)
{
	int change = st[node].change;

	if(change == 0)
		st[node].value = 0;
	else if(change == 1)
		st[node].value = size;
	else if(change == -1)
		st[node].value = size - st[node].value;
	
	if(change != 2) {
		check(node << 1, change);
		check(node << 1 | 1, change);
	}

	st[node].change = 2;
}


void update(int node, int L, int R, int i, int j, int change)
{
	if(L >= i and R <= j)
		check(node, change);

	calc(node, R - L + 1);

	if(L > j or R < i or (L >= i and R <= j))
		return;

	int mid = (L + R) >> 1;

	update(node << 1, L, mid, i, j, change);
	update(node << 1 | 1, mid + 1, R, i, j, change);

	st[node].value = st[node << 1].value + st[node << 1 | 1].value;
}

int query(int node, int L, int R, int i, int j)
{
	calc(node, R - L + 1);

	if(i > R or j < L)
		return 0;

	if(L >= i and R <= j)
		return st[node].value;

	int mid = (L + R) >> 1;

	int l = query(node << 1, L, mid, i, j);
	int r = query(node << 1 | 1, mid + 1, R, i, j);

	st[node].value = st[node << 1].value + st[node << 1 | 1].value; 
	return l + r;
}

int main()
{
	int t; scanf("%d", &t);

	for(int i=1; i<=t; ++i)
	{
		int N = 0;
		int n; scanf("%d ", &n);

		while(n--)
		{
			int k; scanf("%d ", &k);
			char str[210]; scanf("%s", str);

			while(k--){
				strcpy(warrior + N, str);
				N += strlen(str);
			}
		}

		printf("Case %d:\n", i);
		
		int q; scanf("%d ", &q);
		int Q = 0;
		build(1, 0, --N);

		while(q--)
		{
			char op; int x, y;
			scanf("%c %d %d ", &op, &x, &y);

			if(op == 'F')
				update(1, 0, N, x, y, 1);
			else if(op == 'E')
				update(1, 0, N, x, y, 0);
			else if(op == 'I')
				update(1, 0, N, x, y, -1);
			else
				printf("Q%d: %d\n", ++Q, query(1, 0, N, x, y));
			
		}
	}
	return 0;
}