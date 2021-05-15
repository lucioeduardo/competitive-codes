#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int c;

  cin>>c;

  int n,m;

  while(c--){
    cin>>n>>m;

    int res = n/m;
    if(n%m) res++;

    cout << res << endl;
  }
  
  return 0;
}