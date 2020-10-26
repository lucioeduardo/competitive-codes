#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 200020
#define pii pair<int,int>
using namespace std;

int dist[MAXN], cost[MAXN], total=0, tot[MAXN];
vector<pii> graph[MAXN];

int dfs(int v, int d, int c){
  dist[v]=d;
  cost[v]=c;

  for(int i=0; i<graph[v].size(); i++){
    int u = graph[v][i].first, w = graph[v][i].second;

    if(dist[u] == -1){
      dfs(u,d+1,c+w);
      total += w;
    }
  }
}

int main(){
  int n;

  cin>>n;

  for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
    
    graph[a].push_back({b,0});
    graph[b].push_back({a,1});
  }

  init(dist,-1);

  dist[1]=0;

  dfs(1,0,0);

  tot[1]=total;
  int min_v=total;

  for(int i=2; i<=n; i++){
    tot[i] = total - cost[i] + (dist[i]-cost[i]);
    min_v = min(min_v,tot[i]);
  }

  cout << min_v << endl;
  bool f=true;

  for(int i=1; i<=n; i++){
    if(tot[i] == min_v){
      if(!f) cout << " ";
      f=false;
      cout << i;
    }
  }
  

  cout << endl;

  return 0;
}