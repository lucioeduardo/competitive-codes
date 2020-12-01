//https://www.urionlinejudge.com.br/judge/pt/problems/view/1807

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll mod = (1LL << 31) - 1LL;

ll mod_pow(ll b, ll e) {
	ll answer = 1;

	while(e) {
		if(e&1)
			answer = (answer * b) % mod;

		b = (b*b) % mod;
		e >>= 1LL;
	}
	return answer;
}

int main()
{
	ll n;
	cin >> n;
	cout << mod_pow(3, n) << endl;
	return 0;
}