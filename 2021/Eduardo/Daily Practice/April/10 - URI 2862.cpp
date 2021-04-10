#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  while(n--){
    int v;
    cin>>v;

    cout << (v <= 8000 ? "Inseto!" : "Mais de 8000!") << endl;
  }
  
  return 0;
}