// UVa 12356 - Army Buddies

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int S, B;
	int left[100100], right[100100];

	while(scanf("%d %d", &S, &B) && S+B)
	{
		for(int i=1; i<=S; ++i) {
			left[i]  = i - 1;
			right[i] = i + 1;
		}

		left[1] = right[S] = -1;

		while(B--) {

			int a,b;
			scanf("%d %d", &a, &b);
			
			left[right[b]] = left[a];
			right[left[a]] = right[b];

			if(left[a] == -1) printf("*");
			else printf("%d", left[a]);

			if(right[b] == -1) printf(" *\n");
			else printf(" %d\n", right[b]);
		}
		printf("-\n");
	}
	return 0;
}
