#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long unsigned
using namespace std;

string conv_digit(ll v){
  string res="";
  if(v >= 10) res += ('A' + (v-10));
  else res += ('0'+v);

  return res;
}

string base32(ll v){
  if(v < 32){
    return conv_digit(v);
  }

  return base32(v/32LL) + conv_digit(v%32LL);
}

int main(){
  ll v;
  
  while(cin>>v){
    cout << base32(v) << endl;
  }


  return 0;
}