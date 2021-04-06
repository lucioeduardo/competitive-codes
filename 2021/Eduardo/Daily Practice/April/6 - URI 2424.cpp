#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int x,y;

  cin>>x>>y;

  if(x >=0 && x <=432 && y >=0 && y <= 468)
    cout << "dentro" << endl;
  else
    cout << "fora" << endl;
  
  return 0;
}