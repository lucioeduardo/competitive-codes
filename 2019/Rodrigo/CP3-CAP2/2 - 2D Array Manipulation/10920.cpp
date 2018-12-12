// 10920 - Spiral Tap

#include <bits/stdc++.h>

int main()
{
	int n;
	long long int m;

	while(scanf("%d %Ld", &n, &m) && n+m)
	{
		int i = 1;
		int dif = 0;

		while(1LL*i*i < m)
			i += 2;

		while(1LL*n*n > 1LL*i*i)
			n -= 2, ++dif;

		int x = n + dif;
		int y = n + dif;

		long long int target = i * i * 1LL;
		bool flag = true;

		for(int j=0; j<4; ++j)
		{
			for(int k=1; k<i && target != m; ++k)
			{
				if(j < 2) {
					if(flag) --x;
					else --y;
				} else {
					if(flag) ++x;
					else ++y;
				}

				--target;
			}
			flag = !flag;
		}

		printf("Line = %d, column = %d.\n", x, y);

	}
	return 0;
}
