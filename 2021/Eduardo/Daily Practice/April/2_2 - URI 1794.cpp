#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;


int main(){
  int n,la,lb,sa,sb;
  cin>>n>>la>>lb>>sa>>sb;

  if(n>=la && n<=lb && n>=sa && n<=sb)
    cout << "possivel" << endl;
  else
    cout << "impossivel" << endl;
  
  return 0;
}