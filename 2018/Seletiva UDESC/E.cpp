#include <cstdio>

int ans[12];

int main()
{
	int c, x, y;
	int sky[11][4];

	scanf("%d", &c);
	for(int i=1; i<=c; ++i) {
		for(int j=0; j<4; ++j)
			scanf("%d", &sky[i][j]);
	}

	while(scanf("%d %d", &x, &y) && x|y) {

		for(int i=1; i<=c; ++i) {
			if(x >= sky[i][0] && x <= sky[i][1] && y >= sky[i][2] && y <= sky[i][3]) {
				++ans[i];
			}
		}
	}

	for(int i=1; i<=c; ++i)
		printf("CEU #%d: %d estrelas\n", i, ans[i]);
	return 0;
}