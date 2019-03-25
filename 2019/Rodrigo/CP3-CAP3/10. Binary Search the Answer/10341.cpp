#include <bits/stdc++.h>
using namespace std;

double p, q, r, s, t, u;

double func(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * (x * x) + u;
}

int main() {

    while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) != EOF) {
        double lo = 0;
        double hi = 1;
        double target;

        for(int i=0; i<50; ++i) {
            target = (lo + hi) / 2;
            double curr = func(target);

            if(curr > 0)
                lo = target;
            else
                hi = target;
        }

        if(fabs(func(target)) > 1e-9) printf("No solution\n");
        else printf("%.4lf\n", target);
    }

    return 0;
}