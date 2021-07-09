#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int s,a,b;

  while(cin>>s>>a>>b){
    if(a <= b) cout << "impossivel" << endl;
    else{
      double res = (double)s/((double)a-b);
      printf("%.2f\n",res);
    }
  }
  
  return 0;
}