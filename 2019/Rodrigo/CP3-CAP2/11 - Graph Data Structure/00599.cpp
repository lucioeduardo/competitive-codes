#include <bits/stdc++.h>
using namespace std;

vector<int> g[40];
bool seen[40];

void dfs(int u) {
	seen[u] = true;

	for(auto &e : g[u])
		if(!seen[e])
			dfs(e);
}

int main()
{
	int n;
	cin >> n;

	while(n--)
	{
		memset(seen, 0, sizeof seen);
		string edge;

		while(cin >> edge && edge[0] != '*') {
			g[edge[1] - 'A'].push_back(edge[3] - 'A');
			g[edge[3] - 'A'].push_back(edge[1] - 'A');
		}

		int trees = 0;
		int acorns = 0;
		string vertex; cin >> vertex;

		for(int i=0; i<vertex.size(); i += 2) {
			if(seen[vertex[i] - 'A'])
				continue;

			dfs(vertex[i] - 'A');

			if(g[vertex[i] - 'A'].size())
				++trees;
			else
				++acorns;
		}

		cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;

		for(auto &e : g)
			e.clear();
	}
	return 0;
}
