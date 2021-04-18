#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string str;

  while(getline(cin, str)){
    bool b=false, i=false;

    string res = "";

    for(char c: str){
      if(c == '*'){
        if(b) res += "</b>";
        else res += "<b>";

        b = !b;
      }else if(c == '_'){
        if(i) res += "</i>";
        else res += "<i>";
        i = !i;
      }else
        res += c;
    }

    cout << res << endl;
  }
  
  return 0;
}