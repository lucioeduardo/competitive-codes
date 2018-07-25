// https://www.hackerrank.com/challenges/power-of-large-numbers/problem

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll mod = 1000000007LL;

ll fast_exp(ll b, ll e)
{
	ll answer = 1LL;
	while(e) {
		if(e&1)
			answer = (answer * b) % mod;

		b = (b*b) % mod;
		e /= 2;
	}

	return answer;
}

int main()
{
	int n;
	string a,b;
	cin >> n;

	while(cin >> a >> b)
	{
		ll x = 0;
		ll y = 0;

		for(int i=0; a[i]; ++i)
			x = (x * 10 + (a[i]-'0')) % mod;
		for(int i=0; b[i]; ++i)
			y = (y * 10 + (b[i]-'0')) % (mod-1LL);

		cout << fast_exp(x, y) << endl;
	}
	return 0;
}