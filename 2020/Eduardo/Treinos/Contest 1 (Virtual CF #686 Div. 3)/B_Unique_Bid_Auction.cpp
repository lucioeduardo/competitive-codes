#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 200020
using namespace std;

int main(){
  int t;
  vector<int> v(MAXN);
  map<int, int> qtd;

  cin>>t;

  while(t--){
    int n;
    cin>>n;
    qtd.clear();

    for(int i=0; i<n; i++){
      cin>>v[i];
      qtd[v[i]]++;
    }
    
    int res=-1;

    for(auto& x: qtd){
      if(x.second == 1){
        res=x.first;
        break;
      }
    }

    if(res == -1) cout << res << endl;

    for(int i=0; i<n; i++){
      if(v[i] == res)
        cout << i+1 << endl;
    }
  }
  
  return 0;
}