#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  long double a,b;
  int t=1;

  while(cin>>a>>b){
    printf("Projeto %d:\n",t++);
    printf("Percentual dos juros da aplicacao: %.2Lf %%\n\n", (b/a - 1)*100 );
  }

  return 0;
}