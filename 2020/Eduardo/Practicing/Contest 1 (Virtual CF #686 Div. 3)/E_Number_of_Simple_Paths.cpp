#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 200020
using namespace std;

vector<int> graph[MAXN];
int parent[MAXN], d=0;
bool seen[MAXN];
int cycle_start=-1, cycle_end=-1;
vector<int> cycle;

bool find_cycle(int x){
  seen[x]=true;

  for(int i=0; i<graph[x].size(); i++){
    int u = graph[x][i];
    if(!seen[u]){
      parent[u]=x;
      if(find_cycle(u))
        return true;
    }else if(seen[u] && u != parent[x]){
      cycle_start = u;
      cycle_end = x;
      return true;
    }
  }

  return false;
}

int dfs(int x){
  seen[x]=true;

  int res = 1;

  for(int i=0; i<graph[x].size(); i++){
    int u = graph[x][i];
    if(!seen[u]){
      res += dfs(u);
    }
  }

  return res;
}

int main(){
  int t;

  cin>>t;

  while(t--){
    int n;

    cin>>n;

    for(int i=1; i<=n; i++){
      graph[i].clear();
      seen[i]=false;
    }

    for(int i=0; i<n; i++){
      int u,v;

      cin>>u>>v;

      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    find_cycle(1);

    init_arr(seen, false);

    int x = cycle_end;
    while(cycle_start != -1 && x != cycle_start){
      seen[x]=true;
      x = parent[x];
    }
    seen[x]=true;

    ll res=0;

    x = cycle_end;
    while(x != cycle_start){
      ll k = dfs(x);
      res += ((k)*(k-1))/2;
      res += k*(n-k);

      x = parent[x];
    }
    ll k = dfs(x);
    res += ((k)*(k-1))/2;
    res += k*(n-k);


    cout << res << endl;
  }

  return 0;
}