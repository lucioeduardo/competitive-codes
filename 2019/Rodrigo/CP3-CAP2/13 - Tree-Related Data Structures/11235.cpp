#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int left, right;
	int rmq;
} nodetype;

int v[100010];
nodetype st[3 * 100010];

void build(int node, int L, int R)
{
	if(L ^ R) {
		int mid = (L + R) >> 1;
		int l = node << 1;
		int r = l + 1;
		
		build(l, L, mid);	
		build(r, mid + 1, R);

		st[node].left = st[l].left;
		st[node].right= st[r].right;

		if(v[mid + 1] == v[L])
			st[node].left += st[r].left;
		if(v[mid] == v[R])
			st[node].right += st[l].right;

		int current = 0;

		if(v[mid] == v[mid + 1])
			current = st[l].right + st[r].left;
		st[node].rmq = max(current, max(st[l].rmq, st[r].rmq));
	} else {
		st[node].left = st[node].right = st[node].rmq = 1;
	}
}

nodetype query(int node, int L, int R, int i, int j)
{
	
	if(L > j || R < i) return {0, 0, 0};
	if(L >=i && R <=j) return st[node];

	int mid = (L + R) >> 1;
	int l = node << 1;
	int r = l + 1;

	auto lside = query(l, L, mid, i, j);
	auto rside = query(r, mid+1, R, i, j);
	auto current = nodetype();

	current.left  = lside.left;
	current.right = rside.right;

	if(v[mid + 1] == v[L])
		current.left += rside.left;
	if(v[mid] == v[R])
		current.right += lside.right;
	
	current.rmq = 0;
	if(v[mid] == v[mid+1])
		current.rmq = lside.right + rside.left;

	current.rmq = max(current.rmq ,max(lside.rmq, rside.rmq));
	return current;
}

int main()
{
	int N, Q;
	while(scanf("%d %d", &N, &Q) == 2)
	{
		for(int i=1; i<=N; ++i)
			scanf("%d", v + i);

		build(1, 1, N);

		while(Q--) {
			int i, j;
			scanf("%d %d", &i, &j);
			printf("%d\n", query(1, 1, N, i, j).rmq);
		}
	}

	return 0;
}
