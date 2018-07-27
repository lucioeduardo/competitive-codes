// https://www.urionlinejudge.com.br/judge/pt/problems/view/1909

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int gcd(int x, int y) {
	return (x%y) ? gcd(y, x%y) : y;
}

int mmc(int x, int m) {
	return ((1LL*x*m) / gcd(x, m));
}

int main()
{
	int n,t,x;
	while(scanf("%d %d", &n, &t) && (n|t))
	{
		set<int> number;
		number.insert(1);
		int m = 1;
		int answer = t+1;

		for(int i=0; i<n; ++i) {
			scanf("%d", &x);
			number.insert(x);
			m = mmc(x, m);
		}

		for(int i=1; i*i<=t; ++i)
		{
			if(t%i == 0) {
				if(number.find(i) == number.end() && mmc(i, m) == t) {
					answer = i;
					break;
				}

				if(number.find(t/i) == number.end() && mmc(t/i, m) == t)
					answer = (t/i);
			}
		}

		if(answer <= t)
			printf("%d\n", answer);
		else
			printf("impossivel\n");
	}

	return 0;
}