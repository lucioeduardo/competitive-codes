#include <bits/stdc++.h>
#define MAXS 2000
#define PROD 1000000
#define MAXP 2000000000
#define u_int unsigned int

int main() {

    for(u_int i = 1; i <= MAXS && i*i*i*i <= MAXP; ++i) {
        for(u_int j = i; j <= MAXS - i && i*j*j*j <= MAXP; ++j) {
            for(u_int k = j; k <= MAXS - (i + j) && i*j*k*k <= MAXP; ++k) {

                u_int x = i+j+k;
                u_int y = i*j*k; 

                if(y - PROD <= 0) continue;
                if((PROD * x) % (y-PROD)) continue;
                
                u_int l = (PROD * x) / (y - PROD);

                if(x + l > MAXS) continue;
                if(x * l > MAXP) continue;
                if(l < k) continue;
                
                printf("%.2lf %.2lf %.2lf %.2lf\n", i/100.0, j/100.0, k/100.0, l/100.0);
            }
        }
    }

    return 0;
}

/* INSIGHT
    (x + l) * PROD =  y * l
    
    --> PROD * x + PROD * l = y * l
    --> PROD * x = (y * l) - (PROD * l)
    --> l * (y - PROD) = PROD * x
    --> l = (PROD * x) / (y - PROD)
*/