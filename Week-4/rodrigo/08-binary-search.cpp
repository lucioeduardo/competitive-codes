// https://www.spoj.com/problems/BSEARCH1/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, x;
	vector<int> v;
	vector<int>::iterator it;
	scanf("%d %d", &n, &m);

	while(n--) {
		scanf("%d", &x);
		v.push_back(x);
	}

	while(m--) {
		scanf("%d", &x);
		it = lower_bound(v.begin(), v.end(), x);

		if(it != v.end() && (*it) == x)
			printf("%d\n", it - v.begin());
		else
			printf("-1\n");
	}
	return 0;
}