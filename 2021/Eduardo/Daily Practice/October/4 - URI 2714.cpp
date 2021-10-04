#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  while(n--){
    string s;
    cin>>s;

    bool inv = false;

    if(s.length() == 20 && s.substr(0,2) == "RA"){
      int idx=2;
      for(int i=2; i<s.length(); i++){
        if(!isdigit(s[i])) inv = true;
      }

      while(s[idx] == '0' && idx < s.length()-1) idx++;

      if(!inv){
        cout << s.substr(idx,s.length()-idx) << endl;
      }
    }else{
      inv=true;
    }

    if(inv) cout << "INVALID DATA" << endl;
  }
  
  return 0;
}