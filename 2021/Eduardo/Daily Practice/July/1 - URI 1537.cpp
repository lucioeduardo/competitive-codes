#include<bits/stdc++.h>
#define MOD 1000000009
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;


ll res(int n){
  if(n == 3) return 1;

  return (n*res(n-1))%MOD;
}

int main(){
  int n;

  while(cin>>n && n!=0){
    cout << res(n) << endl;
  }
  
  return 0;
}