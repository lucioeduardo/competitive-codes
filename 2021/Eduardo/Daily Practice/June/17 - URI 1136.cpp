#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 95
using namespace std;

int balls[MAXN];
set<int> res;

int main(){
  int n,b;
  

  while(cin>>n>>b && n){
    for(int i=0; i<b; i++){
      cin>>balls[i];
    }

    res.clear();

    for(int i=0; i<b; i++){
      for(int j=0; j<b; j++){
        res.insert(abs(balls[i]-balls[j]));  
      }
    }

    cout << (res.size() == n+1 ? 'Y':'N') << endl;

  }

  return 0;
}