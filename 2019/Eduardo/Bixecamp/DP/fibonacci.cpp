#include <bits/stdc++.h>
#define MAXN 65
#define ll long long
using namespace std;

ll fib[MAXN];


int main(){
    int t;

    fib[0]=0;
    fib[1]=1;

    for(int i=2; i<MAXN; i++)
        fib[i] = fib[i-1]+fib[i-2];

    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);

        printf("Fib(%d) = %lld\n",n,fib[n]);
    }

    return 0;
}