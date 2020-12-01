// https://www.urionlinejudge.com.br/judge/pt/problems/view/2069

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(ll a, ll b)
{
	int r, s;
	int m = max(a, b);

	ll answer = 1;

	for(int i=2; i*i<=m; ++i)
	{
		r = s = 0;
		while(a%i == 0) {
			++r;
			a/=i;
		}

		while(b%i == 0) {
			++s;
			b/=i;
		}

		if(r && s) {
			int k = min(r,s) + min(r, s)%2;
			answer *= pow(i, k/2);
		}
	}

	if(a == b)
		answer *= a;

	return answer;
}

int main()
{
	ll a, b;
	cin >> a >> b;
	cout << solve(a, b) << endl;

	return 0;
}