#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  char c;
  string s;

  int a=0,b=0;

  cin>>c;

  while(cin>>s){
    b++;
    
    for(char ch: s){
      if(ch == c){
        a++;
        break;
      }
    }
  }

  printf("%.1f\n", float(100.0*a)/b);
  
  
  
  return 0;
}