// https://www.urionlinejudge.com.br/judge/pt/problems/view/1602

#include <bits/stdc++.h>
#define MAX 2000006
using namespace std;

bitset<MAX> prime;
int answer[MAX];

void sieve()
{
	prime.set();

	for(int i=2; i*i*1LL < MAX; ++i)
	{
		if(prime[i]) {
			for(int k=i*i; k<MAX; k+=i)
				prime[k] = 0;
		}

		int cont = 3; // inicialmente temos 3 divisores para um numero que é quadrado perfeito (1, sqrt(N), N)
		int curr = i*i;
		
		for(int k=2; k*k < curr; ++k) {
			if(curr % k == 0)
				cont += 2;
		}

		if(prime[cont])
			answer[i*i] = 1;
	}

	for(int i=2; i<MAX; ++i)
		answer[i] += answer[i-1] + prime[i];
}

int main()
{
	int n;
	sieve();

	while(scanf("%d", &n) != EOF)
		printf("%d\n", answer[n]);
	return 0;
}