#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  double a,g,ra,rg;

  cin>>a>>g>>ra>>rg;

  if((1.0/ra)*a < (1.0/rg)*g)
    cout << "A" << endl;
  else
    cout << "G" << endl;
  
  return 0;
}