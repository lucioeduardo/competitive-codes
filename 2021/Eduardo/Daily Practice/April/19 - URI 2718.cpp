#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  ll n;

  cin>>n;

  while(n--){
    ll v;
    cin>>v;

    ll res=0;
    ll at=0;

    for(ll i=0; (1LL<<i) <= v; i++){
      if((1LL<<i) & v) at++;
      else{
        res = max(res,at);
        at=0;
      }
    }

    res = max(res,at);

    cout << res << endl;
  }
  
  return 0;
}

