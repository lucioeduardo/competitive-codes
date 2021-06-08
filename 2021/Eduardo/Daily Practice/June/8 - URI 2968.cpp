#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  ll v,n;

  cin>>v>>n;

  ll m = v*n;

  for(int i=10; i<=90; i+= 10){
    ll res = m*i/100;
    if(m*i % 100) res++;

    cout << res;
    if(i < 90) cout << ' ';
  }

  cout << endl;
  
  return 0;
}