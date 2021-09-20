#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 20010
using namespace std;

int v[MAXN];

int main(){
  int n;

  while(cin>>n && n!=0){
    for(int i=0; i<2*n; i++){
      cin>>v[i];
    }

    sort(v,v+2*n);

    int l=0, r=2*n-1;

    int min_v=99999999;
    int max_v=0;

    while(l < r){
      int x = v[l++] + v[r--];

      //cout << x << endl;

      min_v = min(min_v, x);
      max_v = max(max_v, x);
      
    }

    cout << max_v << " " << min_v << endl;
  }
  
  return 0;
}