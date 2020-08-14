#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  string hello = "hello";

  int it=0;

  cin>>s;

  for(char c: s){
    if(c == hello[it])
      it++;
    if(it == 5) break;
  }

  cout << (it == 5 ? "YES" : "NO") << endl;
  
  return 0;
}