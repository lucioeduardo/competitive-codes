#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  while(cin>>n && n!=-1){
    int res=0;
    int sum=0;
    
    while(n--){
      int v;
      cin>>v;

      sum += v;

      if(sum % 100 == 0) res++;
    }

    cout << res << endl;
  }
  
  return 0;
}