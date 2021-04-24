#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a,b,c;

  cin>>a>>b>>c;

  int d = (a-(b+c));

  cout << max(b, max(c,d)) << endl;
  
  return 0;
}