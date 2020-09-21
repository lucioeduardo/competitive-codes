#include<bits/stdc++.h>
#define MOD 100000000
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

int n1,n2,k1,k2;
int dp[MAXN][MAXN][2];

int solve(int f, int h, bool b){
  if(f == 0 && h == 0) return 1;
  if((f == 0 && b) || (h == 0 && !b)) return 0;
  if(dp[f][h][b] != -1) return dp[f][h][b];

  int res=0;

  if(b){
    for(int i=f-1; i>=f-k1 && i>=0; i--)
      res =  (res + solve(i,h,!b))%MOD;
  }else{
    for(int i=h-1; i>=h-k2 && i>=0; i--)
      res = (res + solve(f,i,!b))%MOD;
  }

  return dp[f][h][b] = res;
}

int main(){
  cin>>n1>>n2>>k1>>k2;

  init(dp,-1);

  int res = (solve(n1,n2,true) + solve(n1,n2,false))%MOD;

  cout << res << endl;

  return 0;
}