#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s;
  string res="";

  cin>>s;

  bool f=false;
  res += s[0];

  for(int i=1; i<s.length(); i++){
    if(!f || !(s[i] == s[i-1]))
      res += s[i];
    
    if(s[i] == s[i-1])
      f=true;
    else
      f=false;
  }

  //cout << res << endl;

  s=res;
  res="";
  res += s[0];
  f= false;

  for(int i=1; i<s.length(); i++){
    //cout << f << " " << res << endl;
    if(!f || !(s[i] == s[i+1]))
      res += s[i];
    
    if(res[res.length()-1] == res[res.length()-2])
      f=true;
    else
      f=false;
  }

  cout << res << endl;
  
  return 0;
}