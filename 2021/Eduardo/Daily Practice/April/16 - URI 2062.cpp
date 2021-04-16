#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;
  string res = "";

  while(n--){
    string s;
    cin>>s;

    if(s.length() == 3){
      string k = s.substr(0,2);

      if(k == "OB")
        s = "OBI";
      else if(k == "UR")
        s = "URI";
    }

    if(!res.empty()) res += ' ';
    res += s;
  }

  cout << res << endl;
  
  return 0;
}