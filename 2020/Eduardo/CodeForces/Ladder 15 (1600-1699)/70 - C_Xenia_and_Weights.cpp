#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXM 1010
using namespace std;

vector<int> weights;

int dp[MAXM][11][11];

bool solve(int m, int d, int last){
  if(m == 0) return true;
  if(dp[m][d][last] != -1) return dp[m][d][last];

  bool res=false;

  for(int i=0; i<weights.size(); i++){
    int w = weights[i];
    if(w > d &&  w != last)
      res = res || solve(m-1,w-d,w);
  }

  return dp[m][d][last] = res;
}

int main(){
  string s;
  int m;

  cin>>s>>m;

  for(int i=0; i<10; i++){
    if(s[i] == '1') weights.push_back(i+1);
  }

  init(dp,-1);

  bool res = solve(m,0,0);
  vector<int> v;

  cout << (res ? "YES":"NO") << endl;

  if(res){
    int d=0;
    int last=-1;
    for(int j=m; j>0; j--){
      for(int i=0; i<weights.size(); i++){
        int w = weights[i];
        if(w > d && w!=last &&  dp[j-1][w-d][w]){
          v.push_back(w);
          d=w-d;
          last=w;
          break;
        }
      }
    }

    cout << v[0];
    for(int i=1; i<v.size(); i++)
      cout << " " << v[i];
    cout << endl;
  }

  


  return 0;
}