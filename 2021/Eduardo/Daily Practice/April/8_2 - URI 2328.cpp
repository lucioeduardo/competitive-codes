#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n, res=0;

  cin>>n;


  while(n--){
    int v;
    cin>>v;

    res += v-1;
  }

  cout << res << endl;
  
  return 0;
}