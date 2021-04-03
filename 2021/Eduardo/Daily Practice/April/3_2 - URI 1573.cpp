#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a,b,c;

  while(cin>>a>>b>>c && !(!a && !b && !c)){
    int vol = a*b*c;

    int res = cbrt(vol);

    cout << res << endl;
  }
  
  return 0;
}