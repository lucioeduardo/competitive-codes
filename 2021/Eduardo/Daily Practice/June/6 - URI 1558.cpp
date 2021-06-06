#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 10010
using namespace std;

bool dp[MAXN];

bool is_perfect_square(int n){
  if(n < 0) return false;
  
  int v = sqrt(n);

  return (v*v == n);
}

int main(){
  int n;

  memset(dp, false, sizeof(dp));

  for(int i=0; i*i < MAXN; i++){
    for(int j=0; (j*j)+(i*i) < MAXN; j++){
      int v = i*i + j*j;
      dp[i*i + j*j] = true;
    }
  }


  while(cin>>n){
    cout << (n >= 0 && dp[n] ? "YES" : "NO") << endl;

  }
  
  return 0;
}