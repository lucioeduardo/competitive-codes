#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

ll res[MAXN];

int main(){
  int n;

  for(int i=1; i<MAXN; i++){
    res[i] = res[i-1] + i*i;
  }

  while(cin>>n && n != 0){
    cout << res[n] << endl;
  }

  return 0;
}