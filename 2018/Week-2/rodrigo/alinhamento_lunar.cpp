// https://www.urionlinejudge.com.br/judge/pt/problems/view/2514

#include <iostream>
#define ll long long int
using namespace std;

ll gcd(ll x, ll m) {
	return (x%m) ? gcd(m, x%m) : m;
}

ll mmc(ll x, ll m) {
	return (x*m) / gcd(x, m);
}

int main()
{
	ll n, x;

	while(cin >> n) {
		ll m = 1;

		for(int i=0; i<3; ++i) {
			cin >> x;
			m = mmc(x, m);
		}

		cout << m-n << endl;
	}
	return 0;
}