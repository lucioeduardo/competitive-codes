#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int cat[] = {1, 3, 5, 10, 25, 50, 100};

int main(){
  int k;

  cin>>k;
  int res=0;

  for(int x: cat){
    if(x >= k) {
      res=x;
      break;
    }
  }

  cout << "Top " << res << endl;
  
  return 0;
}