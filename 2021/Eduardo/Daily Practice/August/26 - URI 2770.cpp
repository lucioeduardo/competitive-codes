#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int x,y,n;

  while(cin>>x>>y>>n){
    if(x < y) swap(x,y);
    
    while(n--){
      int a,b;
      cin>>a>>b;

      if(a<b) swap(a,b);

      if(a <= x && b <= y) cout << "Sim" << endl;
      else cout << "Nao" << endl;
    }
  }
  
  return 0;
}