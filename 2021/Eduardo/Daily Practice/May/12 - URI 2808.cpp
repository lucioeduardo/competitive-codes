#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  char a,b,c,d;

  scanf("%c%c %c%c",&a,&b,&c,&d);

  int x = abs(a-c);
  int y = abs(b-d);

  if((x == 2 && y == 1) || (x==1 && y ==2))
    cout << "VALIDO" << endl;
  else cout << "INVALIDO" << endl;
  
  return 0;
}