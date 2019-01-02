// 11286 - Comformity

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	vector<int> v(5);
	map<vector<int>, int> m;

	while(cin >> n && n)
	{
		int curr = 1;

		while(n--) {
			for(auto &e : v)
				cin >> e;

			sort(v.begin(), v.end());
			curr = max(curr, ++m[v]);
		}
		
		int answer = 0;
		for(auto &e : m)
			if(e.second == curr)
				answer += e.second;
		cout << answer << endl;
		
		m.clear();
	}
	return 0;
}
