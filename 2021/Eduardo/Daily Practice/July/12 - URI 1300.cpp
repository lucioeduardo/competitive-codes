#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  while(cin>>n){
    cout << (n % 6 == 0 ? "Y" : "N") << endl;
  }
  
  return 0;
}