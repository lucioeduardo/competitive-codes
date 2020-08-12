#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;

  int x = 0;

  while(n--){
    string s;
    cin>>s;

    if(s[0] == 'X')
      s = s.substr(1,2);
    else
      s = s.substr(0,2);

    if(s == "++")
      x++;
    else
      x--;
  }

  cout << x << endl;

  return 0;
}