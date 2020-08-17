#include<bits/stdc++.h>
#define MAXN 2020
using namespace std;

int p[MAXN], dep[MAXN];

int solve(int x){
  if(dep[x] != -1) return dep[x];
  if(x == p[x]) return 0;
  return dep[x] = 1 + solve(p[x]);
}

int main(){
  int n;

  cin>>n;

  for(int i=1; i<=n; i++){
    cin>>p[i];
    dep[i] = -1;
  }


  int res=0;

  for(int i=1; i<=n; i++){
    res = max(res, solve(i));
  }

  cout << res << endl;

  return 0;
}