// https://www.spoj.com/problems/HAMSTER1/
// TIME 0.04

#include <bits/stdc++.h>
int v0, k1, k2;

double calc(double target) {
	double x = ((v0*v0) * sin(2 * target)) / 10;
	double y = ((v0*v0) * sin(target) * sin(target)) / 20;

	return k1*x + k2*y;
}

int main()
{
	int n;
	scanf("%d", &n);

	while(n--)
	{
		scanf("%d %d %d", &v0, &k1, &k2);

		double low = 0;
		double high = (M_PI_2);
		double l, r, mid;

		for(int i=0; i<100; ++i)
		{
			mid = (low+high) / 2;

			l = calc(low);
			r = calc(high);

			if(fabs(r-l) < 1e-9)
				break;
			else if(r > l)
				low = mid;
			else
				high = mid;

		}

		printf("%.3lf %.3f\n", mid, calc(mid));
	}

	return 0;
}