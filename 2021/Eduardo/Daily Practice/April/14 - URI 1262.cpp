#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s;
  int n;

  while(cin>>s>>n){
    int q=0,res=0;
    for(int i=0; i<s.length(); i++){
      if(s[i] == 'W'){
        res++;
        res+=q/n + (q % n ? 1 : 0);
        q=0;
      }else{
        q++;
      }
    }

    res+=q/n + (q % n ? 1 : 0);

    cout << res << endl;
  }

  return 0;
}