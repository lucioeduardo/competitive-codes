#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1000100
using namespace std;

int fact[MAXN];

int main(){
  int t;

  cin>>t;

  while(t--){
    ll n, aux;

    cin>>n;
    aux=n;

    int res=n, max_v=1;

    for(ll j=2; j*j<=n; j++){
      int v=0;
      while(n%j == 0){
        v++;
        n/=j;
      }

      if(v > max_v){
        max_v=v;
        res=j;
      }
    }

    cout << max_v << endl;
    if(max_v == 1) cout << aux << endl;
    else{
      while(max_v-- && max_v > 0){
        cout << res << " ";
        aux/=res;
      }

      cout << aux << endl;
    }
    
  }
  
  return 0;
}