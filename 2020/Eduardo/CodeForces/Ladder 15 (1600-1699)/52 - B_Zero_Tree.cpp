#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define pll pair<ll, ll>
#define MAXN 100100
using namespace std;

ll n;
vector<ll> graph[MAXN];
ll w[MAXN];
bool seen[MAXN];

pll dfs(int x){
  seen[x] = true;

  pll s={0,0};

  for(int i=0; i<graph[x].size(); i++){
    int u = graph[x][i];

    if(!seen[u]){
      pll v = dfs(u);
      s.first = max(s.first,v.first);
      s.second = max(s.second,v.second);
    }
  }

  int k = w[x] + s.first - s.second;

  if(k > 0) s.second += (k);
  else s.first += -k;

  return s;
}

int main(){
  
  cin >> n;

  for(int i=1; i<n; i++){
    int u,v;
    cin>>u>>v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for(int i=1; i<=n; i++){
    cin>>w[i];
  }

  pll res = dfs(1);

  cout << res.first+res.second << endl;

  return 0;
}