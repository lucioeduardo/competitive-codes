#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1010
using namespace std;


map<int,int> vals;
int dp[1<<24];

int dif(int a, int b){
  return min(abs(a-b), 24-abs(a-b));
}

int solve(int mask){

  if(mask == 0) return 0;
  if(dp[mask] != -1) return dp[mask];

  int res=999999999;

  vector<int> p;

  for(int i=0; i<24; i++) if(mask & (1<<i)) p.push_back(i);

  for(int i=0; i<p.size(); i++){
    for(int j=i+1; j<p.size(); j++){
      int a = p[i];
      int b = p[j];

      res = min(res, dif(a-11, b-11) + solve(mask ^ (1<<a) ^ (1<<b)));
    }
  }

  return dp[mask]=res;
}

int main(){
  int n;
  cin>>n;

  for(int i=0; i<n; i++){
    int v;
    cin>>v;

    vals[v]++;
  }

  int mask=0;

  for(int i=-12; i<=12; i++){
    int idx = i+11;

    if(vals[i] % 2)
      mask = mask | (1<<idx);
  }

  init(dp,-1);

  cout << solve(mask) << endl;

  return 0;
}