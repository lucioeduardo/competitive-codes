#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;


int main(){
  string s;

  cin>>s;

  int c=0;

  ll oA=0,oB=0,eA=0,eB=0;  
  ll odds=0, even=0;

  for(int i=0; i<s.length(); i++){
    odds++;
    if(i % 2 == 0){
      if(s[i] == 'a'){
        odds += eA;
        even += oA;
        eA++;
      }else{
        odds += eB;
        even += oB;
        eB++;
      }
    }else{
      if(s[i] == 'a'){
        odds += oA;
        even += eA;
        oA++;
      }else{
        odds += oB;
        even += eB;
        oB++;
      }
    }
  }

  cout << even << " " << odds << endl;
  
  return 0;
}