#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,m;
  ll res=0;

  cin>>n>>m;

  int x=1;

  while(m--){
    int v;
    cin>>v;

    if(v < x)
      res += (n-x+v);
    else
      res += (v-x);
    
    x=v;
  }

  cout << res;

  return 0;
}