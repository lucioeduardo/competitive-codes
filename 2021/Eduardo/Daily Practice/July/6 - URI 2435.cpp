#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a,b,c,d,e,f;

  cin>>a>>b>>c>>d>>e>>f;

  if(b*f < c*e) cout << a << endl;
  else cout << d << endl;

  return 0;
}