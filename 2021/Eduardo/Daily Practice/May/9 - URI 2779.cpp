#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,m;

  cin>>n>>m;

  set<int> figs;

  while(m--){
    int v;
    cin>>v;

    figs.insert(v);
  }

  cout << n-figs.size() << endl;
  
  return 0;
}