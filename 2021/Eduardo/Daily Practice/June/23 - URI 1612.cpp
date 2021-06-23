#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;
    int v = n/2;

    int res = min(v+1, n-v);

    cout << res << endl;
  }



  return 0;
}