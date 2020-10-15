#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100010
#define MAXK 505
#define pii pair<int,int>
#define INF 999999999
using namespace std;

vector<pii> graph[MAXN];
int graph_types[MAXK][MAXK];
int type[MAXN], c[MAXK];
int n,m,k;

bool seen[MAXN];

int dfs(int x, int t){
  seen[x] = true;

  int res= (type[x] == t);

  for(int i=0; i<graph[x].size(); i++){
    int u = graph[x][i].first, w = graph[x][i].second;

    if(w == 0 && !seen[u])
      res += dfs(u,t);
  }

  return res;
}

int main(){
  
  cin>>n>>m>>k;

  int it=1;

  for(int i=1; i<=k; i++){
    cin>>c[i];

    for(int j=0; j<c[i]; j++){
      type[it++]=i;
    }
  }

  for(int i=1; i<=k ;i++){
    for(int j=1; j<=k; j++){
      graph_types[i][j] = (i == j ? 0 : INF);
    }
  }

  for(int i=0; i<m; i++){
    int u,v,w;
    cin>>u>>v>>w;

    graph[u].push_back({v,w});
    graph[v].push_back({u,w});

    int a = type[u], b=type[v];

    graph_types[a][b] = min(w, graph_types[a][b]);
    graph_types[b][a] = min(w, graph_types[b][a]);
  }

  it=1;

  bool flag=true;

  for(int i=1; i<=k; i++){
    init(seen,false);
    flag = flag && (dfs(it, type[it]) == c[i]);
    it += c[i];
  }

  if(!flag) cout << "No" << endl;
  else{
    cout << "Yes" << endl;

    for(int w=1; w<=k ;w++)
      for(int i=1; i<=k; i++)
        for(int j=1; j<=k; j++)
          graph_types[i][j] = min(graph_types[i][j], graph_types[i][w] + graph_types[w][j]);

    for(int i=1; i<=k; i++){
        cout << (graph_types[i][1] == INF ? -1 : graph_types[i][1]);
        for(int j=2; j<=k; j++){
          cout << " " << (graph_types[i][j] == INF ? -1 : graph_types[i][j]);
        }
        cout << endl;
    }
  }

  
  return 0;
}