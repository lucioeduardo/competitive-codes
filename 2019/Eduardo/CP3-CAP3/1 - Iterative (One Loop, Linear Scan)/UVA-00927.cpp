#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll val[30];

ll find(ll d, ll k){
    ll qtd=0,i=0;

    while(qtd < k){
       // prllf("%d %d %d\n",qtd,i,k);
        qtd += (++i)*d;
    }

    return i;
}

ll calc(ll n, ll g){
    ll res = 0;
    for(ll i=0; i<=g; i++){
        res += val[i]*pow(n,i);
       // printf("res:%d\n",res);
    }
    return res;
}

int main(){
    ll c;

    scanf("%lld",&c);

    for(ll i=0; i<c; i++){
        ll q;
        scanf("%lld",&q);

        for(ll j=0;j<=q;j++){
            scanf("%lld", &val[j]);
        }

        ll d,k;

        scanf("%lld %lld",&d,&k);

        ll n = find(d,k);

        //printf("n:%d\n",n);
        printf("%lld\n",calc(n,q));


    }

    return 0;
}