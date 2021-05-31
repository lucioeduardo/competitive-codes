#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,m;

  cin>>n>>m;

  int res=0;

  for(int i=0; i<n; i++){
    bool f=true;

    for(int j=0; j<m; j++){
      int x;
      cin>>x;

      if(x == 0) f=false;
    }

    if(f) res++;
  }

  cout << res << endl;
  
  return 0;
}