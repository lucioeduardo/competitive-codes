#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100100
using namespace std;

int d[MAXN];
int nums[MAXN];

int main(){
  int n;

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>nums[i];
  }

  int res=0;

  for(int i=0; i<n; i++){
    int v = nums[i];
    int m=0;
    bool p =true;
    for(int j=2; j*j <= v; j++){
      if(v % j == 0){
        p=false;
        m = max(m, max(d[j],d[v/j]));
      }
    }

    for(int j=2; j*j <= v; j++){
      if(v % j == 0){
        d[j] = d[v/j] = m+1; 
      }
    }

    if(p && v != 1){
      d[v]++;
    }
    res = max(res,m+1);
  }

  cout << res << endl;

  return 0;
}