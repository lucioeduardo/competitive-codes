#include <bits/stdc++.h>
using namespace std;

int search(int *subset, int u) {
	if(subset[u] == u)
		return u;
	return subset[u] = search(subset, subset[u]);
}

void dsu(int *subset, int u, int v) {
	u = search(subset, u);
	v = search(subset, v);

	if(u ^ v)
		subset[u] = v;
}

int main()
{
	int t;
	scanf("%d", &t);

	for(int k=0; k<t; ++k)
	{
		int n; scanf("%d", &n); getchar();
		int successful = 0, unsuccessful = 0;
		int subset[n+1];

		for(int i=1; i<=n; ++i)
			subset[i] = i;

		char op;
		
		while(scanf("%c", &op) != EOF && op != '\n')
		{
			int u, v; scanf("%d %d", &u, &v); getchar();
		
			if(op == 'c') {
				dsu(subset, u, v);
			} else {
				u = search(subset, u);
				v = search(subset, v);

				successful += (u == v);
				unsuccessful += (u != v);
			}
		}

		if(k^0) printf("\n");
		printf("%d,%d\n", successful, unsuccessful);
	}

	return 0;
}
