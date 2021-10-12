#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 50050
using namespace std;

struct edge{
  int u,v,w;
};

vector<edge> edges;
int pai[MAXN];

bool compare(edge a, edge b){
  return a.w < b.w;
}

int find(int x){
  if(pai[x] == x) return x;
  return pai[x] = find(pai[x]);
}

void join(int a, int b){
  int fa = find(a), fb = find(b);

  pai[fa]=fb;
}

int main(){
  int n,m;

  while(cin>>n>>m && n != 0){
    edges.clear();

    for(int i=0; i <= n; i++) pai[i]=i;
    for(int i=0 ;i<m; i++){
      int u,v,w;

      cin>>u>>v>>w;

      edges.push_back({u,v,w});
    }

    sort(edges.begin(), edges.end(), compare);
    int res=0;

    for(int i=0; i<m; i++){
      int u = edges[i].u, v = edges[i].v, w = edges[i].w;

      if(find(u) != find(v)){
        join(u,v);
        res += w;
      }
    }

    cout << res << endl;
  }

  
  return 0;
}