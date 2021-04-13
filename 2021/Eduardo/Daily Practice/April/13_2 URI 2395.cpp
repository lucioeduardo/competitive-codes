#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a,b,c,x,y,z;

  cin>>a>>b>>c>>x>>y>>z;

  cout << ((x/a)*(y/b)*(z/c)) << endl;
  
  return 0;
}