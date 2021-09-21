#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 10010
using namespace std;

vector<int> graph[MAXN];
int qtd[MAXN];

int main(){
  int t;

  cin>>t;

  while(t--){
    int n,m;

    cin>>n>>m;

    memset(qtd,0,sizeof(qtd));

    for(int i=0; i<n; i++) graph[i].clear();

    for(int i=0; i<m; i++){
      int a,b;

      cin>>a>>b;

      graph[b].push_back(a);
      qtd[a]++;
    }

    queue<int> q;

    for(int i=1; i<=n; i++){
      if(qtd[i] == 0) q.push(i);
    }

    while(!q.empty()){
      int v = q.front(); q.pop();

      for(int k: graph[v]){
        qtd[k]--;

        if(qtd[k] == 0) q.push(k);
      }
    }

    bool f=false;

    for(int i=0; i<n; i++){
      if(qtd[i] > 0) f=true;
    }

    cout << (f ? "SIM":"NAO") << endl;
  }
  
  return 0;
}