#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1010
using namespace std;

int v[MAXN];

int main(){
  int n;

  cin>>n;
  int res=1;

  for(int i=0; i<n; i++){
    cin>>v[i];    
  }

  int dif = v[1]-v[0];

  for(int i=2; i<n; i++){
    int k = v[i]-v[i-1];

    if(k != dif){
      res++;
      dif=k;
    }
  }

  cout << res << endl;
  
  return 0;
}