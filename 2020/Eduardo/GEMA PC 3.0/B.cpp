#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int t, tr[4], q[3], v[3];
int dp[4][110][16][16][16];

int solve(int idx, int val, int q1, int q2, int q3){
  if(idx >= 3) return true;
  if(val < 0 || q1 < 0 || q2 < 0 || q3 < 0) return false;
  if(val == 0) return solve(idx+1,tr[idx+1],q1,q2,q3);
  if(dp[idx][val][q1][q2][q3] != -1) return dp[idx][val][q1][q2][q3];
  
  int res=0;

  res = res || solve(idx,val-v[0], q1-1,q2,q3);
  res = res || solve(idx,val-v[1], q1,q2-1,q3);
  res = res || solve(idx,val-v[2], q1,q2,q3-1);  
  
  return dp[idx][val][q1][q2][q3] = res;
}

int main(){

  cin>>t;

  

  while (t--)
  {

    init(dp,-1);
    
    for(int i=0; i<3; i++) cin>>tr[i];

    for(int i=0; i<3; i++) cin>>q[i]>>v[i];

    cout << (solve(0,tr[0],q[0],q[1],q[2]) ? "Yes":"No") << endl;
  }
  

  return 0;
}