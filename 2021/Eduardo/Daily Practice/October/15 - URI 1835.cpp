#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

vector<int> graph[MAXN];
bool seen[MAXN];

void dfs(int x){
  seen[x]=true;

  for(int i=0; i<graph[x].size(); i++){
    int u = graph[x][i];
    if(!seen[u])
      dfs(u);
  }
}

int main(){
  int t;

  cin>>t;

  for(int c=1; c<=t; c++){
    int n,m;

    cin>>n>>m;

    memset(seen,false,sizeof(seen));
    for(int i=1; i<=n; i++) graph[i].clear();

    while(m--){
      int x,y;
      cin>>x>>y;

      graph[x].push_back(y);
      graph[y].push_back(x);
    }

    int res=0;

    for(int i=1; i<=n; i++){
      if(!seen[i]){
        res++;
        dfs(i);
      }
    }

    printf("Caso #%d:", c);

    if(res == 1){
      printf(" a promessa foi cumprida\n");
    }else{
      printf(" ainda falta(m) %d estrada(s)\n", res-1);
    }

  }

  return 0;
}