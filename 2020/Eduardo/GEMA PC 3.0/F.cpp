#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int t;

  cin>>t;

  while(t--){
    string n;
    cin>>n;

    string res="";

    if(n[0] >= n[1]){
      res = n[0];
      if(n[1] > n[2]) res += n[1];
      else res += n[2];
    }
    else{
      res = n[1];
      res += n[2];
    }

    cout << res << endl;
  }
  
  return 0;
}