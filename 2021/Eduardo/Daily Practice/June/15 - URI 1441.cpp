#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  while(cin>>n && n){
    int res=n;

    while(n>1){
      res = max(res,n);

      if(n%2 == 0) n/=2;
      else{
        n = 3*n + 1;
      }
    }

    cout << res << endl;
  }

  return 0;
}