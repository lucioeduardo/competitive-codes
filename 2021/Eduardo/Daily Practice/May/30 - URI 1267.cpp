#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,m;

  while(cin>>n>>m && n){
    bool res = false;
    
    for(int i=0; i<n; i++){
      bool f=true;

      for(int i=0; i<m; i++){
        int v;
        cin>>v;

        if(!v) f=false;
      }

      if(f) res=true;
    }

    cout << (res ? "yes":"no") << endl;
  }

  return 0;
}