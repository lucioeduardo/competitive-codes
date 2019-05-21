#include <bits/stdc++.h>
#define MAXN 110
#define ll long long
using namespace std;

ll dp[MAXN];

int main(){
    dp[1] = 1;

    for(int i=2; i< MAXN; i++){
        dp[i] = dp[i-1] + (i-1)*(i-1) + 2*i-1;
    }

    int n;
    while(scanf("%d",&n) && n){
        printf("%lld\n",dp[n]);
    }


    return 0;
}