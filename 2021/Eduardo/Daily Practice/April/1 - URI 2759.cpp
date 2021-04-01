#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  char a,b,c;

  cin>>a>>b>>c;

  printf("A = %c, B = %c, C = %c\n", a,b,c);
  printf("A = %c, B = %c, C = %c\n", b,c,a);
  printf("A = %c, B = %c, C = %c\n", c,a,b);
  
  return 0;
}