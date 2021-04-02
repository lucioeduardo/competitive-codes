#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int t;

  cin>>t;

  while(t--){
    int n,m;

    cin>>n>>m;
    n-=2;m-=2;

    int a = (n/3) + (n%3 != 0);
    int b = (m/3) + (m%3 != 0);

    cout << a*b << endl;
  }


  return 0;
}