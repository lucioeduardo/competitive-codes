#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(ll x, ll y) {
	return y ? gcd(y, x%y) : x;
}

bool diff(double x, double y) {
	return (x - y) >= 0.0 && (x - y) < 1e-8;
}

int main()
{
	int n;

	while(cin >> n)
	{
		vector<pair<int, int> > v;
		double m = 1.0/n;

		for(ll i=n+1; i <= 2*n; ++i)
		{
			ll j;
			if(i % n)
				j = (i * n) / (i % n);
			else
				j = i;

			double lcm = (i*j) / (double) gcd(i, j);
			double calc = (lcm/i + lcm/j) / lcm;

			if(diff(m, calc))
				v.push_back(make_pair(j, i));

			if(i == j) break;
		}
		cout << v.size() << endl;
		for(int i=0; i<v.size(); ++i)
			cout << "1/" << n << " = 1/" << v[i].first << " + 1/" << v[i].second << endl;
	}

	return 0;
}
