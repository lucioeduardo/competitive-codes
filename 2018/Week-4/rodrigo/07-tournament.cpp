// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=3061

#include <bits/stdc++.h>
using namespace std;

int path[(1 << 15) + 5];

int traverse(int u) {
	if(path[u] == u)
		return u;
	return traverse(path[u]);
}

void search(int u) {
	if(path[u] == u)
		return;
	printf(" %d", path[u]);
	return search(path[u]);
}

int main()
{
	int t;
	int n, k, x;

	cin >> t;

	while(t--) {
		deque<pair<int, int> > qd;
		vector<int> st(1, 0);
		cin >> n >> k;
		n = (1 << n);

		for(int i=1; i<=n; ++i){
			cin >> x;
			qd.push_back(make_pair(x, i));
			st.push_back(x);
			path[i] = i;
		}

		while(qd.size() != 1)
		{
			deque<pair<int, int> > temp;

			for(auto it = qd.begin(); it != qd.end(); it += 2) {
				int u = it->first;
				int v = (it+1)->first;

				int ind_u = it->second;
				int ind_v = (it+1)->second;

				if(u < v) {
					temp.push_back(make_pair(min(st[ind_v], v-u+k), ind_v));
					path[ind_u] = ind_u;
					path[traverse(ind_v)] = ind_u;
				} else {
					temp.push_back(make_pair(min(st[ind_u], u-v+k), ind_u));
					path[ind_v] = ind_v;
					path[traverse(ind_u)] = ind_v;
				}
			}
			qd = temp;
		}
		printf("%d\n%d", qd.begin()->second, path[qd.begin()->second]);
		search(path[qd.begin()->second]);
		printf("\n");
	}
	return 0;
}