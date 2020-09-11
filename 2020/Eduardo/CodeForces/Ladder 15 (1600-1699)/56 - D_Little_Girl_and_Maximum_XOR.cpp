#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  ll l,r;

  cin>>l>>r;

  ll a=0,b=0;

  for(ll i=62; i>=0; i--){    
    ll p = 1LL << i;

    if((p) > r)
      continue;

    if((a + (p) - 1) < l)
      a += (1LL<<i);
    if((b + (p) - 1) < l)
      b += (1LL<<i);

    if(!(a & p) && !(b&p) && a + (p) <= r)
      a += p;
    else if(!(a & p) && !(b&p) && b + p <= r)
      b += p;
  }

  cout << (a^b) << endl;

  
  return 0;
}