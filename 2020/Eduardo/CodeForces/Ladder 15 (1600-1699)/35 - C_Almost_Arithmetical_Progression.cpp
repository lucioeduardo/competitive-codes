#include<bits/stdc++.h>
#define MAXN 4010
using namespace std;

int dp[MAXN][MAXN], v[MAXN], n;
map<int, vector<int>> idx;

int solve(int a, int b){
  if(dp[a][b] != -1) return dp[a][b];

  vector<int> &pos = idx[v[a]];
  vector<int>::iterator it = upper_bound(pos.begin(), pos.end(), b);


  if(it != pos.end())
    return dp[a][b] = 1 + solve(b,*it);

  return dp[a][b] = 1;
}

int main(){

  cin >> n;

  for(int i=0; i<n; i++){
    cin>>v[i];
    idx[v[i]].push_back(i);
  }
  
  memset(dp,-1,sizeof(dp));

  int res=0;

  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      res = max(res,solve(i,j));
    }
  }

  cout << res+1 << endl;
  
  return 0;
}