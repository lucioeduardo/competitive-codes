#include <bits/stdc++.h>
#define MAX 8000
using namespace std;
bool memo[MAX + 10];
vector<int> prime;

void sieve()
{
	memset(memo, 1, sizeof memo);
	memo[1] = false;

	for(int i=2; i <= MAX; ++i) {
		if(memo[i]){
			prime.push_back(i);
			for(int k=i*i; k <= MAX; k += i)
				memo[k] = false;
		}
	}
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	sieve();

	int curr = prime[0] + prime[1] + 1;
	int answer = curr <= n && memo[curr];

	for(int i=0; curr <= n; ++i) {
		curr -= prime[i];
		curr += prime[2+i];

		if(memo[curr] && curr <= n)
			++answer;
	}
	puts(answer < k ? "NO" : "YES");
	return 0;
}