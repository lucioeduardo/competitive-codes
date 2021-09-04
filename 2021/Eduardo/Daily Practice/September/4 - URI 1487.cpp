#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
#define MAXT 620
using namespace std;

int n,t;
ll duration[MAXN], value[MAXN];
ll dp[MAXN][MAXT];

ll solve(int idx, int time){
  if(time == 0 || idx >= n) return 0;
  if(dp[idx][time] != -1) return dp[idx][time];

  ll without = solve(idx+1, time);
  ll with=0;

  if(duration[idx] <= time){
    with = value[idx] + solve(idx, time-duration[idx]);
  }

  return dp[idx][time] = max(with, without);
}

int main(){
  int c=1;

  while(cin>>n>>t && n != 0){
    memset(dp,-1,sizeof(dp));
    
    for(int i=0; i<n; i++){
      cin>>duration[i]>>value[i];
    }

    cout << "Instancia " << c++ << endl;
    cout << solve(0,t) << endl << endl;
  }

  return 0;
}