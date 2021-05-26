#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;


int mdc(int a, int b){
  if(a % b == 0) return b;
  return mdc(b, a%b);
}

int mmc(int a, int b){
  return a*b/mdc(a,b);
}


int main(){
  int n,a,b;

  while(cin>>n>>a>>b && a!=0){
    int res = n/a + n/b - (n/(mmc(a,b)));

    cout << res << endl;
  }


  return 0;
}