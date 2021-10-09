#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 25
using namespace std;

vector<int> graph[MAXN];
bool seen[MAXN];

void print_spaces(int n){
  while(n--) cout << ' ';
}

bool dfs(int x, int dep){
  seen[x] = true;
  bool b = false;

  sort(graph[x].begin(), graph[x].end());

  for(int i=0; i<graph[x].size(); i++){
    int u = graph[x][i];
    print_spaces(dep*2);
    b=true;

    printf("%d-%d", x, u);

    if(!seen[u]){
      printf(" pathR(G,%d)\n", u);
      dfs(u,dep+1);
    }else{
      cout << endl;
    }

    
  }
  
  return b;
}


int main(){
  int t;

  cin>>t;

  for(int c=1; c<=t ; c++){
    cout << "Caso " << c << ":" << endl;
    int n,m;

    cin>>n>>m;

    for(int i=0 ; i<n; i++) graph[i].clear();
    memset(seen, false, sizeof(seen));

    while(m--){
      int u,v;
      cin>>u>>v;

      graph[u].push_back(v);
    }

    for(int i=0; i<n; i++){
      if(!seen[i]){
        if(dfs(i,1))
          cout << endl;
      }
    }
  } 
  
  return 0;
}