#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s,m = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

  
  while(getline(cin,s)){
    string res="";

    for(char c: s){
      if(c == ' ')
        res += c;
      else{
        for(int i=0; i<m.length(); i++){
          if(m[i+1] == c){
            res += m[i];
            break;
          }
        }
      }
    }

    cout << res << endl;
  }


  
  return 0;
}