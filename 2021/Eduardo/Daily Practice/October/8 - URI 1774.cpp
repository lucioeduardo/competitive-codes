#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

struct edge{
  int u,v,w;
};

vector<edge> edges;

bool compare(edge a, edge b){
  return a.w < b.w;
}

int r,c;

int pai[MAXN];

int find(int n){
  if(pai[n] == n) return n;
  return pai[n] = find(pai[n]);
}

void join(int a, int b){
  int fa=find(a), fb=find(b);

  pai[fa]=fb;
}

int main(){

  cin>>r>>c;

  for(int i=0; i<c; i++){
    int u,v,w;
    cin>>u>>v>>w;

    edges.push_back({u,v,w});
  }

  for(int i=1; i<=r; i++) pai[i]=i;

  sort(edges.begin(), edges.end(), compare);

  int res=0;

  for(int i=0; i<c; i++){
    int u = edges[i].u, v = edges[i].v, w = edges[i].w;

    if(find(u) != find(v)){
      join(u,v);
      res += w;
    }
  }

  cout << res << endl;
  
  return 0;
}