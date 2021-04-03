#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int l,d,k,p;

  cin>>l>>d>>k>>p;

  int res = k*l + (l/d)*p;

  cout << res << endl;
  
  return 0;
}