#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 200200
using namespace std;

int pai[MAXN], capacity[MAXN], res[MAXN];

int find(int a){
  if(pai[a] == a) return a;
  return pai[a] = find(pai[a]);
}

void join(int a, int b){
  int fa = find(a), fb=find(b);
  pai[fa] = fb;
}

int main(){
  int n,m;

  cin>>n;

  for(int i=1; i<=n; i++){
    pai[i]=i;
    res[i]=0;
    cin>>capacity[i];
  }

  pai[n+1]=n+1;

  cin>>m;

  for(int i=0; i<m; i++){
    int t;
    cin>>t;

    if(t == 1){
      int p,x;
      cin>>p>>x;

      int idx = find(p);
      while(x + res[idx] >= capacity[idx] && idx <= n){
        
        x -= (capacity[idx] - res[idx]);
        res[idx] = capacity[idx];
        
        int next = idx+1;
        join(idx,next);
        idx = find(idx);
      }

      res[idx] += x;
    }else{
      int k;
      cin>>k;

      cout << res[k] << endl;
    }
  }


  return 0;
}