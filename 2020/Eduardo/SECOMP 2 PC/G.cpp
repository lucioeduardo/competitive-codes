#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a[5],b[5];

  for(int i=0; i<5; i++) cin>>a[i];
  for(int i=0; i<5; i++) cin>>b[i];

  bool res=true;

  for(int i=0; i<5; i++) res = res && (a[i]^b[i]);

  cout << (res ? "Y":"N") << endl;

  return 0;
}