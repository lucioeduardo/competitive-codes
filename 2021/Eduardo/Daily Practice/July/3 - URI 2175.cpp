#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  double o,b,i;

  cin>>o>>b>>i;

  if(o < b && o < i){
    cout << "Otavio" << endl;
  }else if(b < o && b < i){
    cout << "Bruno" << endl;
  }else if(i < o && i < b){
    cout << "Ian" << endl;
  }else{
    cout << "Empate" << endl;
  }
  
  return 0;
}