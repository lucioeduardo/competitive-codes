#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,m;

  while(cin>>n>>m && n){
    int j=99999,v;
    
    for(int i=0; i<n; i++){
      cin>>v;
      j = min(j,v);
    }

    int qtd=0;

    for(int i=0; i<m; i++){
      cin>>v;

      if(v <= j) qtd++;
    }
    cout << (qtd > 1 ? "N":"Y") << endl;
  }
  
  return 0;
}