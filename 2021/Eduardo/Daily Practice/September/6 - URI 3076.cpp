#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  while(cin>>n){
    int res = n/100;

    if(n%100) res++;

    cout << res << endl;
  }
  
  return 0;
}