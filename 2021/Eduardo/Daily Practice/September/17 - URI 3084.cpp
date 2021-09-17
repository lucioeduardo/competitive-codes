#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int h,m;

  while(cin>>h>>m){
    int hour = h/30;
    int min = m/6;

    printf("%02d:%02d\n", hour, min);
    
  }
  
  return 0;
}