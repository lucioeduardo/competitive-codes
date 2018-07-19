//https://www.spoj.com/problems/FACTCG2/

#include <bits/stdc++.h>
#define MAX 10000007

int subset[MAX];

void sieve() {

	for(int i=2; i*i*1LL<MAX; ++i) {
		if(!subset[i]) {
			subset[i] = i;

			for(int k=i*i; k<MAX; k+=i)
				if(!subset[k])
					subset[k] = i;
		}
	}
}

void ouput(int n) {
	putchar('1');
	
	while(subset[n]) {
		printf(" x %d", subset[n]);
		n /= subset[n];
	}

	if(n^1) printf(" x %d\n", n);
	else putchar('\n');
}

int main()
{
	int n;
	sieve();
	
	while(scanf("%d", &n) != EOF)
		ouput(n);
	return 0;
}
