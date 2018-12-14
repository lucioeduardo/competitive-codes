// 11581 - Grid Successors

#include <bits/stdc++.h>

int x[] = {1, 0, -1,  0};
int y[] = {0, 1,  0, -1};

char grid[3][5];

bool isValid(int i, int j) {
	return i >= 0 && j >= 0 && i < 3 && j < 3;
}

int func() {
	int value = 0;
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			value += (grid[i][j] - '0');

	return value;
}

int solve()
{
	char temp[3][5];

	for(int i=0; i<3; ++i) {
		for(int j=0; j<3; ++j) {
			int value = 0;
			for(int k=0; k<4; ++k) {
				int u = i + x[k];
				int v = j + y[k];

				if(isValid(u, v) && grid[u][v] == '1')
					++value;
			}

			temp[i][j] = value&1 ? '1' : '0';
		}
	}

	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			grid[i][j] = temp[i][j];

	return func();
}

int main()
{
	int n;
	scanf("%d\n", &n);

	while(n--)
	{
		scanf(" %s\n%s\n%s", grid[0], grid[1], grid[2]);

		int ans = func() ? 0 : -1;
		while(solve())
			++ans;

		printf("%d\n", ans);
	}
	return 0;
}