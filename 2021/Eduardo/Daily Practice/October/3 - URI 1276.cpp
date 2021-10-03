#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

bool in[260];

int main(){
  string s;

  while(getline(cin,s)){
    memset(in,false,sizeof(in));

    for(char c: s){
      in[c]=true;
    }

    char l='a', r='.';
    bool f=false;


    for(char c='a'; c<='z'; c++){
      if(!in[c]){
        if(r != '.'){
          if(f) cout << ", ";
          printf("%c:%c",l,r);
          f=true;
        }
        l=c+1;
        r='.';
      }else{
        r=c;
      }
    }
    if(r != '.'){
      if(f) cout << ", ";
      printf("%c:%c",l,r);
    }
    cout << endl;
  }


  
  return 0;
}