#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n, s;

  cin>>n>>s;
  int res=s;

  while(n--){
    int v;
    cin>>v;

    s += v;
    res = min(res,s);

  }

  cout << res << endl;
  
  return 0;
}