#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

const double pi = 3.141592654;

int main(){
  double a,b,c;

  while(cin>>a>>b>>c){
    double h = (b * tan(a*pi/180) + c);

    printf("%.2lf\n", h*5);
  }
  
  return 0;
}