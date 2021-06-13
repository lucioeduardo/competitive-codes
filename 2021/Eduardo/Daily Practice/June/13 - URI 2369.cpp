#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  int res = 7;

  if(n > 10) res += min(n,30)-10;
  if(n > 30) res += (min(n,100)-30)*2;
  if(n > 100) res += (n-100)*5;

  cout << res << endl;


  return 0;
}