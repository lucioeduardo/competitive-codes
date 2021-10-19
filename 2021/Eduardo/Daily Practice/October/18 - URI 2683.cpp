#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1010
using namespace std;

int pai[MAXN];

int find(int x){
  if(x == pai[x]) return x;
  return pai[x] = find(pai[x]);
}

void join(int a, int b){
  int fa = find(a), fb = find(b);
  pai[find(a)]=find(b);
}

struct node{
  int u,v,w;
};

vector<node> nodes;

bool compare(node a, node b){
  return a.w < b.w;
}

int main(){
  int m;

  cin>>m;

  for(int i=1; i<MAXN; i++) pai[i]=i;


  for(int i=0; i<m; i++){
    int u,v,w;

    cin>>u>>v>>w;

    nodes.push_back({u,v,w});
  }

  sort(nodes.begin(), nodes.end(), compare);

  int min_v=0, max_v=0;

  for(int i=0; i<m; i++){
    int u = nodes[i].u;
    int v = nodes[i].v;
    int w = nodes[i].w;

    if(find(u) != find(v)){
      join(u,v);
      min_v += w;
    }
  }

  sort(nodes.begin(), nodes.end(), compare);
  for(int i=1; i<MAXN; i++) pai[i]=i;

  for(int i=m-1; i>=0; i--){
    int u = nodes[i].u;
    int v = nodes[i].v;
    int w = nodes[i].w;

    if(find(u) != find(v)){
      join(u,v);
      max_v += w;
    }
  }

  cout << max_v << endl << min_v << endl;
  
  return 0;
}