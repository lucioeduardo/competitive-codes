#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  while(n--){
    double l;
    cin>>l;

    double angle = 36*M_PI/180;    

    double res = (5*l*l)/(4*tan(angle));
    printf("%.3lf\n", res);
  }
  
  return 0;
}