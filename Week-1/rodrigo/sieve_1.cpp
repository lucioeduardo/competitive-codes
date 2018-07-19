#include <bits/stdc++.h>
using namespace std;

void sieve(vector<bool> &prime, int qf) {

	prime[0] = prime[1] = false;

	for(int i=2; i*1LL*i<=qf; ++i) {
		if(prime[i])
			for(int k=i*i; k <= qf; k += i)
				prime[k] = false;
	}
}

int main()
{
	int q0, qf;
	cin >> q0 >> qf;

	vector<bool> prime(qf + 2, true);
	sieve(prime, qf);

	for(int i=2; i<=qf; ++i)
		if(prime[i]) cout << i << endl;
	return 0;
}