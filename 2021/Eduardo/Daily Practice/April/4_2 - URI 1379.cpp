#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a,b;

  while(cin>>a>>b && !(a == b && b == 0)){
    int c = 2*a-b;

    cout << c << endl;
  }
  
  return 0;
}