#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 10010
using namespace std;

bool v[MAXN];

int main(){
  int n,r;

  while(cin>>n>>r){
    memset(v,false,sizeof(v));

    for(int i=0; i<r; i++){
      int x;
      cin>>x;
      v[x]=true;
    }

    bool f=false;

    for(int i=1; i<=n; i++){
      if(!v[i]){
        if(f) cout << ' ';
        cout << i;
        
        f=true;
      }
    }

    if(!f) cout << "*";
    cout << endl;
  }

  



  return 0;
}