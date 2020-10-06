#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  ll n,a,b;

  cin>>n>>a>>b;

  ll res = LLONG_MAX, x,y;
  ll area = 6*n;

  bool f = false;

  if(a < b) f=true;
  if(a < b) swap(a,b);

  for(ll i=b; i*i <= area; i++){
    ll l=a,r=area;

    while(l <= r){
      ll m = (l+r)/2;

      if(i*m >= area){
        
        if(i*m < res){
          res = i*m;
          x=m;
          y=i;
        }
        r = m-1;
      }else{
        l = m+1;
      }

    }
  }
  
  if(f) swap(x,y);
  if(a*b >= area && a*b < res){
    res = a*b;
    x=a;
    y=b;
  };

  cout << res << endl;
  cout << x << " " << y << endl;
  
  return 0;
}