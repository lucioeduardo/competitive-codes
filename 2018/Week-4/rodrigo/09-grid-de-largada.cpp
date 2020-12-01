// https://www.urionlinejudge.com.br/judge/pt/problems/view/1228

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x;

	while(cin >> n)
	{
		vector<int> v, p;

		for(int i=1; i<=n; ++i) {
			cin >> x;
			v.push_back(x);
		}

		for(int i=1; i<=n; ++i) {
			cin >> x;
			p.push_back(x);
		}

		int answer = 0;
		int j;

		for(int i=0; i<n; ++i) {
			int current = v[i];

			for(j=0; j<n; ++j) {
				if(p[j] == current)
					break;
			}

			answer += (j - i);

			for(j; j^i; --j)
				swap(p[j], p[j-1]);
		}

		printf("%d\n", answer);
	}
	return 0;
}