#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  string s;

  cin>>n>>k>>s;

  k--;
  if(k >= n/2) k = n-k-1;

  int res=0;
  int v=0;

  int l=9999999, r=0;

  bool flag=true;

  for(int i=0; i<n/2; i++){
    if(s[i] != s[n-i-1]){
      flag=false;

      char a = s[i], b = s[n-i-1];
      if(a>b) swap(a,b);
      res += min(b-a, ('z'-b)+(a-'a')+1);

      l = min(l, i);
      r = max(r, i);
    }
  }

  res += min(abs(k-l)+abs(r-l), abs(r-k) + abs(r-l));

  if(flag) res=0;

  cout << res <<endl;
  //0 1 2 3 4 5 6
  
  return 0;
}