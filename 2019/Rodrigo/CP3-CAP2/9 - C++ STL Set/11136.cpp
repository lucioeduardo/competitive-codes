#include <bits/stdc++.h>
using namespace std;

multiset<int> m;

int main()
{
	int n;
	while(cin >> n && n)
	{
		unsigned long long answer = 0;
		while(n--) {
			int k; cin >> k;

			while(k--){
				int x; cin >> x;
				m.insert(x);
			}
			answer += (*m.rbegin()) - (*m.begin());
			m.erase(m.begin());
			m.erase(--(m.cend()));

		}
		cout << answer << endl;
		m.clear();
	}
	return 0;
}
