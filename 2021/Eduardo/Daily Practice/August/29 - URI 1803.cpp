#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 88
using namespace std;

int v[MAXN];

int main(){
  string s;
  int n;

  memset(v,0,sizeof(v));

  int mult=1000;
  for(int i=0; i<4; i++){
    cin>>s;
    n = s.length();

    for(int j=0; j<s.length(); j++){
      v[j] += (s[j]-'0')*mult;
    }

    mult/=10;
  }

  string res = "";
  int f = v[0], l = v[n-1];

  for(int i=1; i<n-1; i++){
    res += (char)((f*v[i]+l)%257);
  }

  cout << res << endl;
  return 0;
}