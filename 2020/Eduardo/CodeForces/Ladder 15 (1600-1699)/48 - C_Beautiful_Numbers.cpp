#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1000100
using namespace std;

int a,b,n;
ll res=0;
ll factorial[MAXN], inverse_fact[MAXN], inv[MAXN];

bool good(int x){
  while(x > 0){
    int d = x%10;
    if(d!=a && d!=b)
      return false;
    x/=10;
  }

  return true;
}

long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse_fact[k] % MOD * inverse_fact[n - k] % MOD;
}

void add(int i, int j){
  res = (res + binomial_coefficient(i,j))%MOD;
}

int main(){

  cin>>a>>b>>n;

  inv[1] = 1;
  for(int i = 2; i <= n; ++i)
    inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;

  factorial[0]=1;
  for(int i=1; i<=n; i++)
    factorial[i] = (i*factorial[i-1])%MOD;
  
  inverse_fact[0]=1;
  for(int i=1; i<=n; i++)
    inverse_fact[i] = (inverse_fact[i-1]*inv[i])%MOD;

  for(int i=0; i<=n; i++){
    int j = n-i;
    
    if(good(a*i + b*j)) add(n,j);
  }

  cout << res << endl;
  
  return 0;
}