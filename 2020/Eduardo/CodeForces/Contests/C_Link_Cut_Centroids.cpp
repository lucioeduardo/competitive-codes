#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100100
using namespace std;

vector<int> graph[MAXN];
int qtd[MAXN];
bool seen[MAXN];
vector<int> centroids;
int n;

void dfs(int x){
  seen[x] = true;

  qtd[x]=1;
  bool flag=true;

  for(int i=0; i<graph[x].size(); i++){
    int u = graph[x][i];
    if(!seen[u]){
      dfs(u);
      qtd[x]+= qtd[u];
      if(qtd[u] > n/2) flag=false;
    }
  }

  if(n-qtd[x] > n/2) flag=false;
  if(flag) centroids.push_back(x);
}

int main(){
  int t;

  cin>>t;

  while(t--){

    cin>>n;

    centroids.clear();

    for(int i=1; i<=n; i++) {
      graph[i].clear();
      seen[i]=false;
    }
    for(int i=1; i<n; i++){
      int a,b;
      cin>>a>>b;

      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    dfs(1);


    //for(int i=0; i< centroids.size(); i++) cout << centroids[i] << endl;

    if(centroids.size() == 1){
      int u = centroids[0];

      cout << u << " " << graph[u][0] << endl;
      cout << u << " " << graph[u][0] << endl;
    }else{
      int u = centroids[0];
      int v = centroids[1];

      

      int x=-1;
      for(int i=0; i<graph[v].size(); i++){
        int k= graph[v][i];
        if(k != u) x=k;
      }
      cout << v << " " << x << endl;
      cout << u << " " << x << endl;
    }


   // cout << cent <<

  }
  
  return 0;
}