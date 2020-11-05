#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 5050
using namespace std;

int fence[MAXN];

int solve(int l, int r){
  if(l > r) return 0;
  int res = 0;

  int m=INT_MAX;

  for(int i=l; i<=r; i++){
    m = min(m,fence[i]);
  }

  int prev=l;

  res = m;

  for(int i=l; i<=r; i++){
    fence[i] -= m;

    if(fence[i] == 0){
      res += solve(prev,i-1);
      prev=i+1;
    }
  }

  res += solve(prev,r);

  return min(r-l+1, res);
}

int main(){
  int n;

  cin>>n;

  for(int i=0; i<n; i++) cin>>fence[i];

  cout << solve(0,n-1);

  return 0;
}