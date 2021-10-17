#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1010
using namespace std;

vector<int> graph[MAXN];
bool seen[MAXN];

int dfs(int x){
  int res=1;
  seen[x]=true;

  for(int i=0; i<graph[x].size(); i++){
    int u = graph[x][i];

    if(!seen[u]){
      res += dfs(u);
    }
  }

  return res;
}

int main(){
  int n,m;

  while(cin>>n>>m){
    for(int i=1; i<=n; i++) graph[i].clear();
    memset(seen,false,sizeof(seen));

    while(m--){
      int a,b;
      cin>>a>>b;

      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    int e;
    cin>>e;

    cout << dfs(e) << endl;
  }



  
  return 0;
}