#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 1010
#define ll long long
using namespace std;

int val[MAXN];
int dp[MAXN][2][MAXN];
int n,m,x,y;

int solve(int idx, bool w, int q){
  if(q > y) return 999999999;
  if(idx >= m) return q >= x ? 0 : 99999999;
  if(dp[idx][w][q] != -1) return dp[idx][w][q];

  int q1 = (w ? val[idx] : n-val[idx]) + solve(idx+1,w,q+1);
  int q2 = (w ? n-val[idx] : val[idx]) + solve(idx+1,!w,1);

  if(q < x){
    return dp[idx][w][q] = q1;
  }
  

  //cout << idx << " " << w << " " << w << "| " << q1 << " " << q2 << endl;
  return dp[idx][w][q] = min(q1,q2);
}

int main(){

  cin>>n>>m>>x>>y;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      char c;
      cin>>c;

      if(c == '.') val[j]++;
    }
    getchar();
  }

  memset(dp,-1,sizeof(dp));

  cout << min(solve(0,true,0), solve(0,false,0));

  return 0;
}