/* tentando encontrar o erro */

#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int start;
	int end;
} nodetype;

int v[100010];
nodetype st[3 * 100010];

int freq(nodetype nt) {
	return nt.end - nt.start;
}

void build(int node, int L, int R)
{
	if(L ^ R) {
		int mid = (L + R) / 2;
		int l = 2 * node;
		int r = 2 * node + 1;

		build(l, L, mid);
		build(r, mid + 1, R);

		nodetype a = st[2 * node];
		nodetype b = st[2 * node + 1];

		int A = v[a.start];
		int B = v[b.start];

		if(A == B)
			st[node].start = a.start, st[node].end = b.end;
		else {
			auto p1 = upper_bound(v + a.end, v + b.start, A);
			auto p2 = lower_bound(v + a.end, v + b.start, B);

			int pos_a =(p1 - 1) - v;
			int pos_b = p2 - v;

			if((b.end - pos_b) < (pos_a - a.start))
				st[node].start = a.start, st[node].end = pos_a;
			else
				st[node].start = pos_b, st[node].end = b.end;
		}

		// printf("{%d %d : %d}\n", L, R,	 1 + freq(st[node]));

	} else {
		st[node].start = L;
		st[node].end   = R;
	}
}

pair<int, int> query(int node, int L, int R, int i, int j)
{
	if(L > j || R < i) return {-1, -1};
	if(L >=i && R <=j) return {st[node].start, st[node].end};

	int mid = (L+R) / 2;

	auto l = query(2 * node, L, mid, i, j);
	auto r = query(2 * node + 1, mid+1, R, i, j);

	if(l.first == -1)
		return r;
	if(r.first == -1)
		return l;
	if(v[l.first] == v[r.first])
		return {l.first, r.second};

	auto p1 = upper_bound(v + l.second, v + r.first, v[l.first]);
	auto p2 = lower_bound(v + l.second, v + r.first,     v[r.first]);

	int pos_a = (p1 - 1) - v;
	int pos_b = p2 - v;

	if((r.second - pos_b) < (pos_a - l.first))
		return {l.first, pos_a};
	else
		return {pos_b, r.second};
}

int main()
{	
	int N, q;
	while(scanf("%d %d", &N, &q) == 2)
	{
		for(int i=1; i<=N; ++i)
			scanf("%d", v + i);
		
		build(1, 1, N);

		while(q--) {
			int i,j;
			cin >> i >> j;

			auto answer = query(1, 1, N, i, j);
			cout << 1 + (answer.second - answer.first) << endl;;
		}
	}

	return 0;
}