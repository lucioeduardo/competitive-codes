// https://br.spoj.com/problems/IMPEDIDO/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, x;

	while((cin >> n >> m) && n && m) {
		vector<int> a, d;
		
		while(n--) {
			cin >> x;
			a.push_back(x);
		}
		while(m--) {
			cin >> x;
			d.push_back(x);
		}

		sort(a.begin(), a.end());
		sort(d.begin(), d.end());

		cout << (a[0] < d[1] ? "Y" : "N") << endl;
	}

	return 0;
}