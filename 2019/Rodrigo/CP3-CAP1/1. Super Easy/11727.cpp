#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if(a > b) swap(a, b);
		if(b > c) swap(b, c);
		if(a > b) swap(a, b);
		cout << "Case " << i << ": " << b << endl;
	}
	return 0;
}
