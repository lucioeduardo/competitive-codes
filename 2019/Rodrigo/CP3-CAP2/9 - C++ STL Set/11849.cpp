#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, x, SEEN = 1;
	map<int, int> cd;

	while(cin >> n >> m && n+m) {
		int answer = 0;
		for(int i=0; i<n+m; ++i){
			cin >> x;
			if(cd[x] == SEEN)
				++answer;
			cd[x] = SEEN;
		}
		cout << answer << endl;
		++SEEN;
	}
	cd.clear();
	return 0;
}
