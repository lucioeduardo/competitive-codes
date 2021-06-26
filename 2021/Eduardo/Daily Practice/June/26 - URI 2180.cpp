#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

const int dist = 60e6;

bool is_prime(int n){
  for(int i=2; i*i <=n ;i++){
    if(n % i == 0)
      return false;
  }

  return true;
}

int main(){
  int v;

  cin>>v;

  int x = v;
  int f=0;

  int res=0;

  while(f < 10){
    if(is_prime(x)){
      res += x;
      f++;
    }

    x++;
  }

  printf("%d km/h\n", res);

  int hours = dist/res;
  int days = hours/24;

  printf("%d h / %d d\n",hours, days);
  return 0;
}