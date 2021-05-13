#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s,d;

  while(cin>>s){
    cin>>d;
    bool f=false;

    int n = d.length();

    for(int i=0; i<s.length(); i++){      
      bool x = true;

      if(i+n > s.length()) break;

      for(int j=0; j<n; j++){
        if(s[i+j] != d[j]) x=false;
      }

      f = f || x;

    }

    cout << (f ? "Resistente":"Nao resistente") << endl;
  }
  
  return 0;
}