#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1010
using namespace std;


int main(){
  int t;

  cin>>t;

  while(t--){
    int n;
    cin>>n;

    int sq = sqrt(n);

    cout << n - sq << endl;
  }
  
  return 0;
}