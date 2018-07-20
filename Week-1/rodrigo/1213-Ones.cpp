//https://www.urionlinejudge.com.br/judge/pt/problems/view/1213

#include <stdio.h>

int main()
{
	int n, i, r;

	while(scanf("%d", &n) != EOF)
	{
		i = 1;
		r = i%n;

		while(r)
			r = (r * 10 + 1) % n, ++i;

		printf("%d\n", i);
	}
	return 0;
}
