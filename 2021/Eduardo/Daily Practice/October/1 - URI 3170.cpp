#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a,b;

  cin>>a>>b;

  int res = b/2 - a;

  if(res <= 0) cout << "Amelia tem todas bolinhas!" << endl;
  else cout << "Faltam " << res << " bolinha(s)" << endl;
  
  return 0;
}