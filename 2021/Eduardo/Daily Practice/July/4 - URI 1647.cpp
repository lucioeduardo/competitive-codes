#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 55
using namespace std;

int v[MAXN];

int main(){
  int n;

  while(cin>>n && n!=0){
    for(int i=0; i<n; i++)
      cin>>v[i];

    ll res=0;

    for(int i=n-1; i>=0; i--){
      res += res + v[i];
    }

    cout << res << endl;
  }
  
  return 0;
}