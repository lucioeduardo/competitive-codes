#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int val(char c){
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 's')
    return 3;
  return 2;
}

int main(){
  int t;

  cin>>t;

  while(t--){
    string s;

    cin>>s;

    ll res=1;

    for(char c: s){
      res *= val(tolower(c));
    }

    cout << res << endl;
  }
  
  return 0;
}