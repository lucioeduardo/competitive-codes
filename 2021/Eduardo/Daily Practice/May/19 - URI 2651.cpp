#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s;

  getline(cin,s);

  bool res=false;

  int n = s.length();

  for(int i=0; i<n; i++){
    s[i] = tolower(s[i]);
  }

  for(int i=0; i<n-4 && !res; i++){
    if(s.substr(i,5) == "zelda") res=true;
  }

  cout << (res ? "Link Bolado": "Link Tranquilo") << endl;
  return 0;
}