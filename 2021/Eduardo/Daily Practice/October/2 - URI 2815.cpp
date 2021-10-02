#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string res = "";
  string w;

  while(cin>>w){
    if(!res.empty()) res += ' ';

    if(w.length() >= 4 && w.substr(0,2) == w.substr(2,2)){
      w = w.substr(2,w.length()-2);
    }

    res += w;
  }

  cout << res << endl;
  
  return 0;
}