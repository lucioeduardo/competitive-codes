// https://br.spoj.com/problems/TENTA/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test = 0;
	int n, x;
	vector<int> v;

	while((cin >> n) && n) {
		for(int i=0; i<n; ++i) {
			cin >> x;
			v.push_back(x);
		}

		sort(v.begin(), v.end());

		if(++test^1)
			cout << endl;

		do {
			for(int i=0; i<n-1; ++i)
				cout << v[i] << " ";
			cout << v[n-1] << endl;
		} while(next_permutation(v.begin(), v.end()));
		v.clear();
	}
	return 0;
}