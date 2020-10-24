#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 30
using namespace std;

int pos[MAXN], chg[MAXN];

int main(){
  int n;

  while(cin>>n){
    for(int i=1;i<=n;i++){
      int v;
      cin>>v;
      pos[v]=i;
    }

    int res=0;

    for(int i=1; i<=n; i++){
      int v;
      cin>>v;

      chg[v]=i;
    }

    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(pos[i] > pos[j] && chg[i] < chg[j]) res++;
      }
    }

    cout << res << endl;
  }

  return 0;
}