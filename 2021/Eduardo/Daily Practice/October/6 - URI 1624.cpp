#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

int price[MAXN], weight[MAXN];
int dp[MAXN][MAXN];
int n;

int solve(int idx, int p){
  if(p<0) return -99999999;
  if(idx >= n) return 0;
  if(dp[idx][p] != -1) return dp[idx][p];

  int com = price[idx] + solve(idx+1, p-weight[idx]);
  int sem = solve(idx+1, p);

  return dp[idx][p] = max(com,sem);
}

int main(){

  while(cin>>n && n != 0){
    memset(dp, -1, sizeof(dp));

    for(int i=0; i<n; i++){
      cin>>price[i]>>weight[i];
    }
    int w;
    cin>>w;

    cout << solve(0,w) << endl;
  }

  
  return 0;
}