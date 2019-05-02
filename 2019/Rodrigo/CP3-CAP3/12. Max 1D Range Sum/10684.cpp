#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, x;

	while(scanf("%d", &n) && n) {
		int curr = 0;
		int ans  = 0;

		while(n--) {
			scanf("%d", &x);

			curr += x;
			ans = max(ans, curr);
			curr = max(curr, 0);
		}

		if(ans)
			printf("The maximum winning streak is %d.\n", ans);
		else
			printf("Losing streak.\n");
	}
}
