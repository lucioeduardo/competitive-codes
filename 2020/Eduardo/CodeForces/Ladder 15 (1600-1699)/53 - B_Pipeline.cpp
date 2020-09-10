#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

ll n,k,u;
ll sum_pa(int v){
  ll dif = u-v;
  return (dif+1)*(2*v+dif)/2;
}

int main(){

  cin>>n>>k;

  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }
  ll v = min(n,k);

  n-=v;
  ll res=1;

  u = v-2;
  ll esq=1, dir=u;

  ll k=u+1;

  while(esq <= dir){
    ll meio = (esq+dir)/2;

    if(sum_pa(meio) <= n){
      k=meio;
      dir=meio-1;
    }else{
      esq=meio+1;
    }
  }

  if(sum_pa(k) == n) cout << (u-k)+2;
  else if(n - sum_pa(k) < k) cout << (u-k)+3;
  else cout << -1 << endl;

  return 0;
}