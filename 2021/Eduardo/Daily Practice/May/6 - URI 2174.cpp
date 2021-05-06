#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  set<string> pokemons;

  int n;
  cin>>n;
  string s;

  while(n--){
    cin>>s;
    pokemons.insert(s);
  }
  int res = (151 - pokemons.size());

  printf("Falta(m) %d pomekon(s).\n", res);

  return 0;
}