#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,c,v;

  cin>>n;
  cin>>c;

  bool f = true;

  for(int i=0; i<n-1; i++){
    cin>>v;
    if(v > c) f = false;
  }

  cout << (f ? 'S': 'N') << endl;
  
  return 0;
}