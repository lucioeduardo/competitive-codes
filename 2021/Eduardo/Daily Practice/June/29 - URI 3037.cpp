#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int t;

  cin>>t;

  while(t--){
    int j=0,m=0,x,d;

    for(int i=0; i<3; i++){
      cin>>x>>d;

      j += x*d;
    }

    for(int i=0; i<3; i++){
      cin>>x>>d;

      m += x*d;
    }

    if(j>m) cout << "JOAO" << endl;
    else cout << "MARIA" << endl;
  }

  return 0;
}