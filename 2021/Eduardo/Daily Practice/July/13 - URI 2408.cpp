#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a,b,c;

  cin>>a>>b>>c;

  if(b>c) swap(b,c);
  if(a>b) swap(a,b);
  if(b>c) swap(b,c);

  cout << b << endl;

  return 0;
}