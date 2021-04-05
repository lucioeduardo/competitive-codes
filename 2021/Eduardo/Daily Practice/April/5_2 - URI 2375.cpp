#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  bool f=true;
  int x;

  cin>>n;

  for(int i=0; i<3; i++){
    cin >> x;
    if(x < n) f=false;
  }

  cout << (f ? "S":"N") << endl;
  
  return 0;
}