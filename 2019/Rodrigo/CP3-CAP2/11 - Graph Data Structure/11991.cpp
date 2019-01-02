#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		vector<pair<int, int> > problem;

		for(int i=1; i<=n; ++i) {
			int p; cin >> p;
			problem.push_back({p, i});
		}

		sort(problem.begin(), problem.end());
		while(m--) {
			int k, v; cin >> k >> v;

			auto i = upper_bound(problem.begin(), problem.end(), make_pair(v-1, n));
			auto f = upper_bound(problem.begin(), problem.end(), make_pair(v, n));

			if((f-i) >= k)
				cout << problem[(i - problem.begin()) + k-1].second << endl;
			else
				cout << 0 << endl;
		}
	}

	return 0;
}
