#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  while(cin>>n){
    getchar();
    string s;
    while(n--){
      getline(cin,s);

      int nP=0, nS=0;
      for(char c: s){
        if(c == ' ')
          nS++;
        else nP++;
      }

      int res = nS*3 + (nP/(nS+1));

      char c = 'a'+(res-1);
      cout << c << endl;
    }
  }
  
  return 0;
}