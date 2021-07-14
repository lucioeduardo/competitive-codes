#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n, t=1;

  while(cin>>n && n!=0){
    int res=-1;
    for(int i=1; i<=n; i++){
      int v;
      cin>>v;

      if(v == i) res=i;
    }

    cout << "Teste " << t++ << endl;
    cout << res << endl << endl;
  }
  
  return 0;
}