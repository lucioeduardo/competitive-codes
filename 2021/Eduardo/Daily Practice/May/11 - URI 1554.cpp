#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 55
#define pii pair<int,int>
using namespace std;

pii balls[MAXN];
int x,y;

int calc_dist(int idx){
  return (balls[idx].first-x)*(balls[idx].first-x) + (balls[idx].second-y)*(balls[idx].second-y);
}

int main(){
  int t;

  cin>>t;

  while(t--){
    int n;

    cin>>n;

    int res=0;

    cin>>x>>y;

    for(int i=0;i<n;i++){
      int a,b;
      cin>>a>>b;

      balls[i] = {a,b};

      if(calc_dist(i) < calc_dist(res))
        res=i;
    }

    cout << res+1 << endl;
  }
  
  return 0;
}