#include<bits/stdc++.h>
#define MAXN 100100
#define pii pair<int,int>
using namespace std;

vector<pii> graph[MAXN];
vector<int> res;
bool seen[MAXN];
int num[MAXN];

int dfs(int x){
  seen[x] = true;

  int c=0;

  int qtd=0;

  for(int i=0; i<graph[x].size(); i++){
    int u = graph[x][i].first, w = graph[x][i].second;

    if(w == 2)  c=1;

    if(!seen[u]){
      qtd += dfs(u);
    }
  }

  qtd+=c;

  if(qtd == 1) res.push_back(x);

  return qtd;
}

int main(){
  int n;

  cin>>n;

  for(int i=0; i<n; i++){
    int u,v,w;
    cin>>u>>v>>w;

    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
  }

  dfs(1);

  int q = res.size();

  cout << q << endl;

  if(q){
    cout << res[0];
    for(int i=1; i<res.size(); i++){
      cout << " " << res[i];
    }

    cout << endl;
  }

  return 0;
}