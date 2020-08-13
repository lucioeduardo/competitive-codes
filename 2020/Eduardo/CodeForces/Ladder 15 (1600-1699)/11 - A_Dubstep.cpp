#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;

  cin>>s;

  string act="", res="";


  for(int i=0; i<s.length(); i++){
    if(s.substr(i,3) == "WUB"){
      i += 2;

      if(!act.empty()){
        if(!res.empty()) res += ' ';
        res += act;
        act = "";
      }
    }else{
      act += s[i];
    }

  }

  if(!act.empty()){
    if(!res.empty()) res += ' ';
    res += act;
  }

  cout << res << endl;
  
  return 0;
}