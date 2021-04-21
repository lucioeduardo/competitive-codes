#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXV 220
using namespace std;

ll v[MAXV];

int main(){
  ll n,t=1;

  while(cin>>n && n){
    ll p=0,c=0;

    memset(v,0,sizeof(v));

    while(n--){
      ll a,b;

      cin>>a>>b;

      v[b/a] += a;

      p+=a;
      c+=b;
    }


    bool f=false;

    printf("Cidade# %lld:\n",t++);

    for(int i=0; i<MAXV; i++){
      if(v[i] == 0) continue;

      if(f) cout << " ";
      f=true;
      printf("%lld-%d",v[i],i);
      
    }

    string res = to_string((double)c/p);
    res = res.substr(0, res.length()-4);

    printf("\nConsumo medio: %s m3.\n\n", res.c_str());
  }
  
  return 0;
}