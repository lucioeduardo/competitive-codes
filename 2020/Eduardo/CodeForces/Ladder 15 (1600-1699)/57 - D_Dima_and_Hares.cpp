#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 3030
using namespace std;

int a[MAXN],b[MAXN],c[MAXN];
int dp[MAXN][2];
int n;

int solve(int idx, bool f){
  if(idx == n-1){
    if(f) return b[idx];
    else return a[idx];
  }
  if(dp[idx][f] != -1) return dp[idx][f];

  int res=0;


  if(f) res = max(b[idx] + solve(idx+1,true), c[idx]+solve(idx+1,false));
  else res = max(a[idx] + solve(idx+1, true), b[idx]+solve(idx+1,false));

  return dp[idx][f]=res;
}

int main(){

  cin>>n; 

  for(int i=0;i<n; i++) cin>>a[i];
  for(int i=0;i<n; i++) cin>>b[i];
  for(int i=0;i<n; i++) cin>>c[i];

  init(dp,-1);

  cout << solve(0,false) << endl;

  return 0;
}