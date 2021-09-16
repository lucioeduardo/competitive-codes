#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

int dp[MAXN][MAXN][MAXN];
int pA[MAXN], pB[MAXN], pC[MAXN];

int solve(int a, int b, int c){
  if(a+b+c == 0) return true;
  if(dp[a][b][c] != -1) return dp[a][b][c];

  int res = 0;

  for(int i=0; i<2; i++){
    if(i && a <= 0) continue;
    for(int j=0; j<2; j++){
      if(j && b <= 0) continue;
      for(int k=0; k<2; k++){
        if(k && c <= 0) continue;

        if(i+j+k == 0) continue;

        int sum = 0;
        if(i) sum += pA[a-1];
        if(j) sum += pB[b-1];
        if(k) sum += pC[c-1];

        if(sum % 3 == 0) res = res || solve(a-i,b-j,c-k);
      }
    }
  }


  return dp[a][b][c] = res;
}

int main(){
  int n;

  while(cin>>n && n != 0){
    memset(dp,-1,sizeof(dp));

    for(int i=0; i<n; i++){
      cin>>pA[i]>>pB[i]>>pC[i];
    }

    cout << solve(n,n,n) << endl;
  }
  
  return 0;
}