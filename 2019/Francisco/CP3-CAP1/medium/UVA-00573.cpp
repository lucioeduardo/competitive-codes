#include <bits/stdc++.h>

using namespace std;

int main(){

    double h, u, d, f, dec, curr;
    int day;

    while(true){
        day = 0, curr = 0;

        scanf("%lf %lf %lf %lf", &h, &u, &d, &f);

        if(h == 0) break;

        dec = u * (f/100);

        while(true){
            day++;

            curr += u;
        
            u = (u>0)?u-dec:0;

            if(curr > h) break;

            curr -= d;

            if(curr < 0) break;
        }

        if(curr < 0){
            printf("failure on day %d\n", day);
        } else{
            printf("success on day %d\n", day);
        }
    }

    return 0;
}