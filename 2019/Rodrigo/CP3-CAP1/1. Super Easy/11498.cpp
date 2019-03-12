#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k, x,y, u,v;

	while(cin >> k && k) {
		cin >> u >> v;

		while(k--) {
			cin >> x >> y;

			if(x > u && y > v) cout << "NE"  << endl;
			else if(x < u && y > v) cout << "NO" << endl;
			else if(x < u && y < v) cout << "SO" << endl;
			else if(x > u && y < v) cout << "SE" << endl;
			else cout << "divisa" << endl;
		}

	}
	return 0;
}
