#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  
  cin>>s;

  bool flag = false;
  int v=1;
  char x = '-';

  for(char c: s){
    if(c == x)
      v++;
    else
      v=1;
    x=c;

    if(v >= 7)
      flag=true;
  }

  cout << (flag ? "YES":"NO") << endl;

  return 0;
}