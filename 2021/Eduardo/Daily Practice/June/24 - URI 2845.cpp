#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100100
using namespace std;

bool flag[MAXN];
set<int> factors;

int main(){
  int n;
  cin>>n;
  int m=1;

  for(int i=0; i<n; i++){
    int v;
    cin>>v;

    m = max(m,v);

    for(int j=2; j*j<=v; j++){
      if(v % j == 0){
        factors.insert(j);
        factors.insert(v/j);
      }
      
      while(v % j == 0)
        v /= j;
    }
    
    //factors.insert(v);
    
  }

  for(int f: factors){
    for(int i=f; i<MAXN; i+=f){
      flag[i]=true;
    }
  }

  int res=-1;

  for(int i=m+1; i<MAXN; i++){
    if(!flag[i]){
      res=i;
      break;
    }
  }

  cout << res << endl;

  return 0;
}