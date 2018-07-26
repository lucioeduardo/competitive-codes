#include <stdio.h>
#include <vector>
#define MAX 2000001

using namespace std;

vector<int> prime;
bool isPrime[MAX];
int r[MAX];

bool hyperPrime(int a){
    int i = 0, expo = 0, mult = 1, f = prime[i];

    while(a != 1 && a >= f*f){
        while(a % f == 0){
            expo++;
            a /= f;
        }
        if(expo > 0 && (a != 1 || !isPrime[expo+1])) return false;
        f=prime[++i];
        mult *= expo+1;
        expo = 0;
    }

    return true;
}

void sieve(){
    int i, j, c = 0;

    for(i = 2; i <= MAX; i++) isPrime[i] = true;

    for(i = 2; i <= MAX; i++)
        if(isPrime[i]){
            r[i] = ++c;
            prime.push_back(i);
            if(i*1ll*i <= MAX)
                for(j = i*i; j <= MAX; j += i)
                    isPrime[j] = false;
        } else{
            if(hyperPrime(i))
                r[i] = ++c;
            else
                r[i] = c;
        }
}

int main(){

    int n;

    sieve();

    while(scanf("%d", &n) != EOF){
        printf("%d\n", r[n]);
    }

    return 0;
}