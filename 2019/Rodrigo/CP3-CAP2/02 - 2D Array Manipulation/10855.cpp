// 10855 - Rotated square
#include <bits/stdc++.h>

int main()
{
	int n, m;

	while(scanf("%d %d", &n, &m) && n+m)
	{
		char A[n][n+2], B[m][m+2];

		int a,b,c,d;
		a = b = c = d = 0;

		for(int i=0; i<n; ++i)
			scanf("%s", A[i]);

		for(int i=0; i<m; ++i)
			scanf("%s", B[i]);

		for(int i=0; i<=n-m; ++i) {
			for(int j=0; j<=n-m; ++j) {
				bool fa, fb, fc, fd;
				fa = fb = fc = fd = true;

				for(int r=0; r<m; ++r) {
					for(int c=0; c<m; ++c) {
						char curr = A[i+r][j+c];

						if(curr != B[r][c]) fa = false;
						if(curr != B[(m-c)-1][r]) fb = false;
						if(curr != B[(m-r)-1][(m-c)-1]) fc = false;
						if(curr != B[c][(m-r)-1]) fd = false;
					}
				}
				
				a += fa; b += fb;
				c += fc; d += fd;
			}

		}

		printf("%d %d %d %d\n", a,b,c,d);

	}

	return 0;
}