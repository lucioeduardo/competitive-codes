#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,c;

  cin>>n>>c;
  int q=0;
  bool f=false;

  while(n--){
    int a,b;

    cin>>a>>b;

    q += (b-a);

    if(q>c) f=true;
  }

  cout << (f ? "S":"N") << endl;

  return 0;
}