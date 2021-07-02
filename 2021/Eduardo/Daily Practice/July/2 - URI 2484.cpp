#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

void print_str(string s){
  cout << s[0];
  for(int i=1; i<s.length(); i++){
    cout << ' ' << s[i];
  }
}

int main(){
  string s;

  while(cin>>s){
    for(int i=0; i<s.length(); i++){
      int k=i;
      
      while(k--) cout << ' ';

      print_str(s.substr(0, s.length()-i));
      cout << endl;
    }

    cout << endl;
  }
  
  return 0;
}