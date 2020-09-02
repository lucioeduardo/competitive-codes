#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;

set<int> v[MAXN];
int color[MAXN];

int main(){
  int n,m;

  cin>>n>>m;

  int maxC=0;
  int minC=9999999;

  for(int i=1; i<=n; i++){
    cin>>color[i];
    maxC = max(maxC, color[i]);
    minC = min(minC, color[i]);
  }

  for(int i=0; i<m; i++){
    int a,b;
    cin>>a>>b;

    if(color[a] == color[b]) continue;

    v[color[a]].insert(color[b]);
    v[color[b]].insert(color[a]);
  }

  int res=minC;

  for(int i=1; i<= maxC; i++){
    if(v[i].size() > v[res].size())
      res = i;
  }

  cout << res << endl;
  
  return 0;
}
