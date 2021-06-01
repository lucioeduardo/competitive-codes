#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int v[5];

  for(int i=0;i<5;i++) cin>>v[i];

  int d = (v[0] > v[1] ? 1 : -1);


  bool f=true;

  for(int i=2; i<5; i++){
    int x = (v[i] < v[i-1] ? 1 : -1);

    if(x != d) f=false;
  }

  if(f) cout << (d == 1 ? "D" : "C") << endl;
  else cout << "N" << endl;



  
  return 0;
}