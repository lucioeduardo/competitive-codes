#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

ll n_2(ll n){
  return (n)*(n-1)/2;
}

ll n_4(ll n){
  return (n)*(n-1)*(n-2)*(n-3)/24;
}

int main(){
  int n;

  cin>>n;


  cout << (1 + n_2(n) + n_4(n)) << endl;
  

  return 0;
}