#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 500050
using namespace std;

ll v[MAXN];


int main(){
  int n;
  ll sum=0;
  cin>>n;

  for(int i=0; i<n; i++){
    cin>>v[i];
    sum += v[i];
  }

  if(sum % 3 == 0){
    ll a = sum/3, b = 2*sum/3;
    ll qA=0, res=0;

    ll at=0;

    for(int i=0; i<n; i++){
      at += v[i];
      if(at == b && i > 0 && i < n-1) res += qA;
      if(at == a) qA++;
    }

    cout << res << endl;
  }else{
    cout << 0 << endl;
  }

  
  return 0;
}