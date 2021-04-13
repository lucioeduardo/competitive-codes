#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define pii pair<int,int>
#define MAXN 110
using namespace std;

bool compare(pii a, pii b){
  return a.second < b.second;
}

int main(){
  vector<pii> v;

  int n,m;
  cin>>n>>m;

  for(int i=1; i<=n; i++){
    int s=0;
    for(int j=0; j<m; j++){
      int x;
      cin>>x;
      s+=x;
    }
    v.push_back({i,s});
  }

  sort(v.begin(), v.end(), compare);
  
  for(int i=0; i<3; i++)
    cout << v[i].first << endl;

  return 0;
}