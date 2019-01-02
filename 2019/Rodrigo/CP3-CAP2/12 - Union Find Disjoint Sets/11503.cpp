#include <bits/stdc++.h>
using namespace std;

map<string, string> m;
map<string, int> friendship;

string search(string u) {

	if(m.find(u) == m.end()) {
		if(!friendship[u]) friendship[u] = 1;
		return u;
	}

	return m[u] = search(m[u]);
}

int dsu(string a, string b) {
	a = search(a);
	b = search(b);

	if(a != b) {
		m[a] = b;
		friendship[b] += friendship[a];
	}

	return friendship[b];
}

int main()
{
	int t; cin >> t;
	
	while(t--)
	{
		int n; cin >> n;

		while(n--) {
			string a, b;
			cin >> a >> b;
			cout << dsu(a, b) << endl;
		}

		m.clear();
		friendship.clear();
	}
	return 0;
}
