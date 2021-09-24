#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int t=1;

  int r,w,l;

  while(cin>>r && r!=0){
    cin>>w>>l;

    if(4*r*r >= w*w + l*l){
      printf("Pizza %d fits on the table.\n", t);
    }else{
      printf("Pizza %d does not fit on the table.\n", t);
    }

    t++;
  }

  return 0;
}