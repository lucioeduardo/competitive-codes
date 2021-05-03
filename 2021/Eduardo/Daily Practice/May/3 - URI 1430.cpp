#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int note_val(char c){
  if(c == 'W') return 64;
  if(c == 'H') return 32;
  if(c == 'Q') return 16;
  if(c == 'E') return 8;
  if(c == 'S') return 4;
  if(c == 'T') return 2;
  if(c == 'X') return 1;
  return 0;
}

int main(){
  string s;

  while(cin>>s && s!="*"){
    int v=0;
    int res=0;
    
    for(char c: s){
      if(c == '/'){
        if(v == 64) res++;
        v=0;
      }

      v += note_val(c);
    }

    cout << res << endl;
  }

  return 0;
}