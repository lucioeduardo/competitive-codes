#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  while(cin>>n){
    double res=99999;

    while(n--){
      double v;

      cin>>v;

      res = min(res,v);
    }

    printf("%.2lf\n", res);
  }
  
  return 0;
}