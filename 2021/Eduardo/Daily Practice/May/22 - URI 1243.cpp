#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s;

  while(getline(cin,s)){
    int sum=0, qtd=0;

    bool f=true;
    int at=0;

    for(int i=0; i<s.length(); i++){
      char c = s[i];
      if(c == ' '){
        if(f && at){
          qtd++;
          sum+=at;
        }
        at=0;
        f=true;
      }else if(isalpha(c)){
        at++;
      }else{
        if(c == '.' && (i == s.length()-1 || s[i+1] == ' '))
          continue;
        f=false;
      }
    }

    if(f && at){
      qtd++;
      sum+=at;
    }

    int res = qtd == 0 ? 0 : sum/(double)qtd;

    //cout << res << " " << qtd << endl;

    if(res <= 3){
      cout << 250 << endl;
    }else if(res <= 5) cout << 500 << endl;
    else cout << 1000 << endl;
  }

  return 0;
}