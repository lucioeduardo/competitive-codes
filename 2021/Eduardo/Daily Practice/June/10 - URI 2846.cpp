#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  int a=1, b=1;

  while(true){
    int dif = (a-b-1);

    if(dif >= n) break;

    n -= max(0,dif);

    int aux = a;
    a = a+b;
    b = aux;

    //cout << a << " " << b << endl;
  }

  cout << b+n << endl;
  
  return 0;
}