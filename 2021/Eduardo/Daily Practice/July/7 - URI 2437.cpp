#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a,b,c,d;

  cin>>a>>b>>c>>d;

  cout << abs(a-c) + abs(b-d) << endl;
  
  return 0;
}