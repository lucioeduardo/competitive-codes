#include <stdio.h>
#define SIZE 2000001

int prime[SIZE];

int hyperPrime(int a){
    int i = 0;
    int expo = 0;
    int mult = 1;
    int f = prime[i];

    while(a != 1 && a >= f*f){
        while(a % f == 0){
            expo++;
            a /= f;
        }
        f=prime[++i];
        mult *= expo+1;
        expo = 0;
    }
    if(a != 1) mult *= (++expo)+1;

    return mult;
}

int main(){

    int n;

    while(scanf("%d", &n) != EOF){

        int c = 0;
        int p = 0;
        int i;
        int j;
        bool isPrime[n+1];

        for(i = 2; i <= n; i++) isPrime[i] = true;

        for(i = 2; i <= n; i++)

            if(isPrime[i]){

                prime[p++] = i;
                c++;

                if(i* 1ll *i <= n)
                
                    for(j = i*i; j <= n; j += i)
                        isPrime[j] = false;  

            } else{

                if(isPrime[hyperPrime(i)])
                    c++;

            }

        printf("%d\n", c);
    }

    return 0;
}