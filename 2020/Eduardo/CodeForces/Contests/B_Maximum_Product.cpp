#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100100
using namespace std;

int n;
ll v[MAXN];

int main(){
  int t;

  cin>>t;
  
  while(t--){
    cin >> n;

    for(int i=0; i<n; i++){
      cin>>v[i];
    }

    sort(v, v+n);
    int l=0, r=n-1;
    ll res=1;
    
    if(v[n-1] < 0){
      for(int i=1; i<=5; i++) res*=v[n-i];
    }else{
      res = v[r--];

      for(int i=0;i<2; i++){
      if(v[r]*v[r-1] > v[l]*v[l+1]){
        res *= (v[r]*v[r-1]);
        r-=2;
      }else{
        res *= (v[l]*v[l+1]);
        l += 2;
      }
    }
    }

    
    
    cout << res << endl;
  }
  
  return 0;
}