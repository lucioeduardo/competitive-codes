#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 20
using namespace std;

int main(){
  ll res[MAXN];

  res[1]=0;
  res[2]=1;

  bool s=true;

  for(int i=3; i<MAXN; i++){
    if(s) res[i] = res[i-1]+res[i-2];
    else res[i] = res[i-1]*res[i-2];

    s = !s;
  }

  int n;

  while(cin>>n){
    cout << res[n] << endl;
  }
  return 0;
}