#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int t;

  cin>>t;

  while(t--){
    int n;
    cin>>n;

    cout << n;
    for(int i=1; i<n; i++){
      cout << " " << i;
    }

    cout << endl;
  }
  
  return 0;
}