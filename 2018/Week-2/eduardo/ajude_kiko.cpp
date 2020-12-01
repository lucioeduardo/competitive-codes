//URI 1909 - Ajude Kiko
#include <stdio.h>
#include <set>
using namespace std;

set<long long> tempos;

long long gcd(long long a, long long b){
if(a % b == 0)
  return b;
return gcd(b, a%b);
}

int main(){
    long long n,t;

    while(scanf("%lld %lld",&n, &t) && !(n==0 && t==0)){
      tempos.clear();

      long long v, mmc=1;
      for (size_t i = 0; i < n; i++) {
        scanf("%lld",&v);
        tempos.insert(v);
        mmc = (mmc*v)/gcd(mmc,v);
      }
      long long min=-1;
      for(long long i=2; i*i <= t; i++){
        if(t % i == 0){
          if(tempos.find(i) == tempos.end()){
            long long k = i*mmc/gcd(i,mmc);
            if((i < min || min == -1) && k == t)
              min = i;
          }
          if(tempos.find(t/i) == tempos.end()){
            long long k = (t/i)*mmc/gcd(t/i,mmc);
            if((t/i < min || min == -1) && k == t)
              min = t/i;
          }
        }
      }

      if(tempos.find(t) == tempos.end() && min == -1 && (mmc*t)/gcd(mmc,t) == t)
        min=t;

      if(min == -1)
        printf("impossivel\n");
      else
        printf("%lld\n",min);

    }

    return 0;
  }
