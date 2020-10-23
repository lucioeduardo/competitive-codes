#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXM 110
using namespace std;

ll n, m;
ll dp[1<<18][MAXM];
vector<int> digits;

ll solve(int mask, int k){
  ll res=0;
  int p = digits.size() - 1 - __builtin_popcount(mask);

  if(p < 0) return k == 0;

  if(dp[mask][k] != -1) return dp[mask][k];

  ll mult = pow(10LL,p);
  mult %= m;

  for(int i=0; i < digits.size(); i++){
    if(mask & (1<<i)) continue;
    if(p == digits.size()-1 && digits[i] == 0) continue;
    if(i>0 && !(1<<i-1 & mask) && digits[i] == digits[i-1]) continue;

    ll r = (k + mult*digits[i])%m;
    res += solve(mask | (1<<i), r);
  }

  return dp[mask][k] = res;
}

int main(){
  cin>>n>>m;

  ll aux=n;

  while(aux>0){
    digits.push_back(aux%10);
    aux/=10;
  }

  sort(digits.begin(), digits.end());

  init(dp,-1);

  cout << solve(0,0) << endl;

  return 0;
}