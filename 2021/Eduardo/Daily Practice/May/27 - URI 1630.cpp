#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int gcd(int a, int b){
  if(a % b == 0) return b;
  return gcd(b,a%b);
}

int main(){
  int n,m;

  while(cin>>n>>m){
    int d = gcd(n,m);

    int res = 2*(n/d+1) + 2*m/d - 2;

    cout << res << endl;
  }
  
  return 0;
}