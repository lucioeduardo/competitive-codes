#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

const ll maxr = 1e13;

int n[3],p[3],q[3];
ll r;

bool can(ll v){
  ll g=0;

  for(int i=0; i<3; i++){
    if(q[i] != 0){
      g += max((q[i]*v - n[i])*p[i], 0LL);
    }
  }

  //cout << v << " " << g << endl;

  return (g <= r);
}

int main(){
  string str;

  cin>>str;

  for(char c: str){
    if(c == 'B') q[0]++;
    if(c == 'C') q[2]++;
    if(c == 'S') q[1]++;
  }

  for(int i=0;i<3;i++) cin>>n[i];
  for(int i=0;i<3;i++) cin>>p[i];

  cin>>r;

  ll res=0;
  
  ll esq=0, dir= maxr;

  while(esq <= dir){
    ll meio = (esq+dir)/2;

    if(can(meio)){
      res = meio;
      esq=meio+1;
    }else{
      dir=meio-1;
    }
  }

  cout << res << endl;

  return 0;
}