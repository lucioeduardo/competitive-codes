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

    int res=0;

    while(n--){
      int v;
      cin>>v;

      res += (v-1);
    }

    cout << res+1 << endl;
  }
  
  return 0;
}