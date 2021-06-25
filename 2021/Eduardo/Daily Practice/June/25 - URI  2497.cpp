#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,t=1;

  while(cin>>n && n!=-1){
    printf("Experiment %d: %d full cycle(s)\n",t++,n/2);
  }
  
  return 0;
}