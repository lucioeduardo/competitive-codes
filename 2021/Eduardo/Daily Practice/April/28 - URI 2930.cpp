#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;

  int d = b-a;

  if(b-a >= 3){
    cout << "Muito bem! Apresenta antes do Natal!" << endl;
  }else{
    if(d < 0) cout << "Eu odeio a professora!" << endl;
    else if(a+2 < 24) cout << "Parece o trabalho do meu filho!\nTCC Apresentado!" << endl;
    else cout << "Parece o trabalho do meu filho!\nFail! Entao eh nataaaaal!" << endl;
  }
  
  return 0;
}