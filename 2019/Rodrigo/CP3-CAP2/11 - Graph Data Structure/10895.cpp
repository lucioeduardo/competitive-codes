#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		vector<pii> M[m+1];

		for(int i=1; i<=n; ++i)
		{
			int k; cin >> k;

			vector<int> v(k);
			for(auto &e : v)
				cin >> e;

			for(int l=0; l<k; ++l) {
				int x; cin >> x;
				M[v[l]].push_back({i, x});
			}
		}

		cout << m << " " << n << endl;
		for(int i=1; i<=m; ++i) {
			int size = M[i].size();

			if(size) {
				cout << size;

				for(auto &e : M[i])
					cout << " " << e.first;
				cout << endl;
				
				for(int j=0; j<M[i].size(); ++j){
					if(j) cout << " ";
					cout << M[i][j].second;
				}
				cout << endl;
			} else {
				cout << 0 << "\n\n";
			}
		}
	}

	return 0;
}
