#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXV 1010
using namespace std;

vector<int> graph[MAXV];
bool seen[MAXV];

int dfs(int v){
  seen[v]=true;

  int res=0,qtd=0;
  vector<int> q;

  for(int i=0; i<graph[v].size(); i++){
    int u = graph[v][i];
    if(!seen[u]){
      int k = dfs(u);

      q.push_back(k+1);
      qtd++;
    }
  }

  if(qtd > 0){
    sort(q.begin(), q.end());
    res = q[qtd-1];
    int at=res;

    for(int i=qtd-1; i>=0; i--){

      if(q[i] > at){
        at++;
        res++;
      }
      at--;
    }
  }
  

  return res;
}

int main(){
  int t;

  cin>>t;

  while(t--){
    int v,r;

    cin>>v>>r;

    for(int i=0; i<=v; i++) graph[i].clear();
    memset(seen,false, sizeof(seen));

    for(int i=0; i<v-1; i++){
      int u,w;
      cin>>u>>w;

      graph[u].push_back(w);
      graph[w].push_back(u);
    }

    cout << dfs(r) << endl;
  }

  return 0;
}