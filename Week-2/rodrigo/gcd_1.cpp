#include <stdio.h>

int gcd(int x, int y) {
	return (x%y) ? gcd(y, x%y) : y;
}

int main()
{
	int t, n, x;
	scanf("%d", &t);

	while(scanf("%d", &n) != EOF) {
		int answer = 0;

		while(n--) {
			scanf("%d", &x);
			answer = gcd(answer, x);
		}
		puts(answer^1 ? "NO" : "YES");
	}
	return 0;
}