#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int t;

  cin>>t;

  while(t--){
    int n,m;

    cin>>n>>m;

    int res = m*log10(n)+1;

    cout << res << endl;
  }
  
  return 0;
}