// 10038 - Jolly Jumpers

#include <bits/stdc++.h>
using namespace std;

bool f[3010];

int main()
{
	int n;
	while(cin >> n)
	{
		memset(f, 0, sizeof f);
		vector<int> v(n);

		for(auto &e : v)
			cin >> e;

		for(int i=0; i<n-1; ++i)
			f[abs(v[i] - v[i + 1])] = true;

		int ans = 0;
		for(int i=1; i<n; ++i)
			ans += f[i];

		printf("%s\n", ans == (n-1) ? "Jolly" : "Not jolly");
	}

	return 0;
}
