#include<bits/stdc++.h>
using namespace std;

bool div(string a, string b){
  int n = a.length();
  int m = b.length();

  if(n % m != 0) return false;

  bool flag=true;

  for(int i=0; i<=n-m; i+=m){
    if(a.substr(i,m) != b){
      return false;
    }
  }

  return true;
}

int main(){
  string a,b;

  cin>>a>>b;

  if(a.length() > b.length()) swap(a,b);

  vector<string> divs;

  int l=1;
  int n = a.length();

  for(int l=1; l*l<=n; l++){
    if(n % l != 0) continue;

    string s = a.substr(0,l);
    if(div(a,s)) divs.push_back(s);

    if(l == n/l) continue;

    s = a.substr(0,n/l);
    if(div(a,s)) divs.push_back(s);
  }

  n = b.length();
  int res=0;
  for(string s: divs){
    if(div(b,s)) res++;
  }

  cout << res << endl;

  return 0;
}