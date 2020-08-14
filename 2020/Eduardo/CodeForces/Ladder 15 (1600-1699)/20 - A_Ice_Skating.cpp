#include<bits/stdc++.h>
#define MAXN 110
using namespace std;

typedef pair<int,int> pii;

vector<pii> points;
bool seen[MAXN];

void dfs(int x){
  seen[x] = true;

  for(int i=0; i<points.size(); i++){
    if(i == x || seen[i]) continue;

    if(points[i].first == points[x].first || points[i].second == points[x].second)
      dfs(i);
  }
}

int main(){
  int n;

  cin>>n;

  while(n--){
    int a,b;
    cin>>a>>b;

    points.push_back({a,b});
  }

  int res=0;

  for(int i=0; i<points.size(); i++){
    if(!seen[i]) {
      res++;
      dfs(i);
    }
  }
  
  cout << res-1 << endl;

  return 0;
}