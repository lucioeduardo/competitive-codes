#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

int v[MAXN];


int main(){
  int n,c,m;
  
  cin>>n>>c>>m;

  for(int i=0; i<c; i++){
    int x;
    cin>>x;
    v[x]=1;
  }

  for(int i=0; i<m; i++){
    int x;
    cin>>x;

    c-= v[x];
    v[x]=0;
  }

  cout << c << endl;



  return 0;
}