#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s;

  while(cin>>s){
     bool f=true;

    int q=0, res=0;

    for(char c: s){
      if(c == 'o') q++;
      if(c == 'x'){
        if(f) res = max(res,q);
        else res = max(res, q/2);
        f=false;
        q=0;
      }
    }
    res = max(res,q);
    cout << res << endl;
  }
 
  
  return 0;
}