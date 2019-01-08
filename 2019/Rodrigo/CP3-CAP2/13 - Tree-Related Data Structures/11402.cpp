// TLE 5s

#include <bits/stdc++.h>
#define MAXN (1 << 10) * 1001
using namespace std;

int N;
int bit[MAXN];

void update(int x, int value)
{
	while(x < N) {
		bit[x] += value;
		x += (x&-x);
	}
}

int query(int x)
{
	int answer = 0;

	while(x) {
		answer += bit[x];
		x -= (x&-x);
	}

	return answer;
}

int main()
{
	int t; scanf("%d", &t);

	for(int i=1; i<=t; ++i)
	{
		warrior = "0";
		memset(bit, 0, sizeof bit);
		int n; scanf("%d ", &n);

		while(n--)
		{
			int k; scanf("%d ", &k);
			char str[210]; scanf("%s", str);

			while(k--)
				warrior += string(str);
		}
	
		int q; scanf("%d ", &q);

		for(int k=1; warrior[k]; ++k){
			if(warrior[k] == '1')
				update(k, 1);
		}

		printf("Case %d:\n", i);
		int Q = 0;

		while(q--)
		{
			char op; int x, y;
			scanf("%c %d %d ", &op, &x, &y);
			++x, ++y;

			if(op == 'F') {
				while(x <= y) {
					if(warrior[x++] == '1')
						continue;

					warrior[x - 1] = '1';
					update(x - 1, 1);
				}

			} else if(op == 'E') {
				while(x <= y) {
					if(warrior[x++] == '0')
						continue;

					warrior[x - 1] = '0';
					update(x - 1, -1);
				}

			} else if(op == 'I') {
				while(x <= y) {

					if(warrior[x] == '0') {
						update(x, 1);
						warrior[x++] = '1';

					} else {
						update(x, -1);
						warrior[x++] = '0';
					}
				}

			} else
				printf("Q%d: %d\n", ++Q, query(y) - query(x - 1));
		}
	}
	return 0;
}