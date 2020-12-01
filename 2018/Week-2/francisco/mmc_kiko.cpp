/** Help Kiko **/
#include <stdio.h>
#include <set>

using namespace std;

long long gcd(long long a, long long b){
    if(a%b == 0)
        return b;
    return gcd(b, a%b);
}

int main(){

    long long n, t;

    while(scanf("%lld", &n) && n != 0){
        scanf("%lld", &t);
        long long mmc = 1;
        long long v;
        set<long long> values;
        values.insert(1);

        for(int i = 0; i < n; i++){
            scanf("%lld", &v);
            values.insert(v);
            mmc = (mmc*v)/gcd(mmc,v);
        }
        
        long long k;
        long long answer = -1;
        for(long long i = 1; i*i <= t; i++){
            if(t % i == 0){

                k = (i*mmc)/gcd(i, mmc);
                if(values.find(i) == values.end() && k == t){
                    answer = i;
                    break;
                }

                k = ((t/i)*mmc)/gcd(t/i, mmc);
                if(values.find(t/i) == values.end() && k == t){
                    answer = t/i;
                }

            }
        }

        if(answer != -1)
            printf("%lld\n", answer);
        else
            printf("impossivel\n");
    }

    return 0;
}