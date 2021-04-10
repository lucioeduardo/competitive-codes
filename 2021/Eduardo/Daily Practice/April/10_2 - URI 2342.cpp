#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,a,b;
  char c;

  cin>>n;
  cin>>a>>c>>b;

  int res = 0;

  if(c == '+') res = a+b;
  else res = a*b;

  cout << (res > n ? "OVERFLOW" : "OK") << endl;
  
  return 0;
}