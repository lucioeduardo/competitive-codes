#include<bits/stdc++.h>
#define MOD 1000000007
#define P 11
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

unordered_map<ll, string> s;

ll calc_hash(string s){
  long long hash_value = 0;
  long long p_pow = 1;
  for (char c : s) {
      hash_value = (hash_value + (c - 'a' + 1) * p_pow) % MOD;
      p_pow = (p_pow * P) % MOD;
  }
  return hash_value;
}

int main(){
  int n,m;

  cin>>n>>m;

  for(int i=0; i<n; i++){
    string str;
    cin>>str;

    s[calc_hash(str)]=str;
  }

  for(int i=0; i<m; i++){
    string str;
    cin>>str;

    bool res=false;

    ll h = calc_hash(str);

    long long p_pow = 1;

    for(int j=0; j<str.length() && !res; j++){
      char c = str[j];

      for(char k = 'a'; k <= 'c' ; k++){
        if(k != c){
          ll hash_v = (h + (k-c)*p_pow + 3LL*MOD)%MOD;

          str[j] = k;
          if(s.count(hash_v) && s[hash_v] == str) res=true;
        }
      }

      str[j]=c;
      
      p_pow = (p_pow*P)%MOD;
    }

    cout << (res ? "YES":"NO") << endl;
  }

  return 0;
}