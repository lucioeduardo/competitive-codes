#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 505
using namespace std;

int n;
ll d[MAXN][MAXN], del[MAXN], res[MAXN];



int main(){

  cin>>n;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin>>d[i][j];
    }
  }

  for(int i=1; i<=n; i++){
    cin>>del[i];
  }

  for(int k=n; k>=1; k--){
    ll u = del[k];

    for(int i=1; i<=n; i++){
      ll v = del[i];
      for(int j=1; j<=n; j++){
        ll w = del[j];
        d[v][w] = min(d[v][w], d[v][u] + d[u][w]);
        
        if(i >= k && j >= k) res[k]+=d[v][w];
      }
    }
  }

  cout << res[1];
  for(int i=2; i<=n; i++)
    cout << " " << res[i];
  cout << endl;
  return 0;
}