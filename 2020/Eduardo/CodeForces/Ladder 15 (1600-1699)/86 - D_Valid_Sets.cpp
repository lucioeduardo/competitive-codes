#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 2020
using namespace std;

int d,n,a[MAXN];
vector<int> graph[MAXN];
bool seen[MAXN];

ll dfs(int x, int r){
  seen[x] = true;

  int res=1;

  for(int i=0; i<graph[x].size(); i++){
    int v = graph[x][i];

    if(a[v] == a[r] && v < r) continue;
    if(!seen[v] && a[v]-a[r] <= d && a[v] >= a[r])
      res =  (res * (1+dfs(v,r)))%MOD;
  }

  return res;
}

int main(){
  cin>>d>>n;

  for(int i=1; i<=n; i++) cin>>a[i];
  for(int i=1; i<n; i++){
    int u,v;
    cin>>u>>v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  ll res=0;

  for(int i=1; i<=n; i++){
    memset(seen,false,sizeof(seen));
    res += (dfs(i,i))%MOD;
    res %= MOD;
  }

  cout << res << endl;

  return 0;
}