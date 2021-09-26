#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  for(int i=1; i<=n; i++){
    int v;
    cin>>v;
    
    printf("resposta %d: %d\n", i, v);
  }
  
  return 0;
}