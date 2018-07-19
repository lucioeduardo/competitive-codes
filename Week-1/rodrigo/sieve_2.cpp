#include <bits/stdc++.h>
using namespace std;

vector<int> answer(1003);

void solve()
{
	int size = 2;

	for(int i=43; size <= 1000; ++i)
	{
		int curr = 0;
		int number = i;

		for(int k=2; (k*k) <= i; ++k) {
			if(number%k == 0) {
				++curr;
				while(number%k == 0)
					number /= k;
			}
		}

		if(number > 1) ++curr;
		if(curr >= 3) answer[++size] = i;
	}
}

int main()
{
	int n, x;

	scanf("%d", &n);
	answer[1] = 30;
	answer[2] = 42;

	solve();

	while(n--) {
		scanf("%d",&x);
		printf("%d\n", answer[x]);
	}
	return 0;
}