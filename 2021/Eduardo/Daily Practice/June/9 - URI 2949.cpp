#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

map<char,int> res;

int main(){
  int n;

  cin>>n;

  string s;
  char c;

  while(n--){
    cin>>s>>c;

    res[c]++;
  }

  printf("%d Hobbit(s)\n", res['X']);
  printf("%d Humano(s)\n", res['H']);
  printf("%d Elfo(s)\n", res['E']);
  printf("%d Anao(s)\n", res['A']);
  printf("%d Mago(s)\n", res['M']);
  
  return 0;
}