#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  int a=0, b=0;
  int resA=0, resB=0;

  cin>>n;

  while(n--){
    string x, y;

    cin>>x>>y;

    if(x == "chuva"){
      if(a == 0){
        resA++;
        a++;
      }

      a--;
      b++;
    }

    if(y == "chuva"){
      if(b == 0){
        resB++;
        b++;
      }

      b--;
      a++;
    }
  }

  cout << resA << " " << resB << endl;
  
  return 0;
}