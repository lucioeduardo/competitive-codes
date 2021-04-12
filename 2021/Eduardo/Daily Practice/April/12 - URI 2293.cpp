#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

int field[MAXN][MAXN];

int main(){
  int n,m;

  cin>>n>>m;

  int res=0;

  for(int i=0; i<n; i++){
    int s=0;
    for(int j=0; j<m; j++){
      cin>>field[i][j];
      s += field[i][j];
    }

    res = max(res,s);
  }

  for(int i=0; i<m; i++){
    int s=0;
    for(int j=0; j<n; j++){
      s += field[j][i];
    }
    res = max(res,s);
  }

  cout << res << endl;

  
  
  return 0;
}