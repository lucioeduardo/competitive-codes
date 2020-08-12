#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;

  cin>>n;

  while(n--){
    string s;
    cin>>s;

    int l = s.length();

    if(l <= 10)
      cout << s << endl;
    else{
      printf("%c%d%c\n", s[0], l-2, s[l-1]);
    }
  }

  return 0;
}