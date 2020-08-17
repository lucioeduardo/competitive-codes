#include<bits/stdc++.h>
#define MAXN 150010
using namespace std;

int sum[MAXN];

int main(){

  int n,k;
  cin>>n>>k;

  cin>>sum[0];

  for(int i=1; i<n; i++){
    cin>>sum[i];
    sum[i] += sum[i-1];
  }

  int res=0;

  for(int i=0; i+k<n; i++){
    //cout << sum[i+k] - sum[i] << endl;

    if(sum[res+k] - sum[res] > sum[i+k] - sum[i]){
      res = i;
    }
  }

  if(n <= k || sum[k-1] <= sum[res+k] - sum[res]) res=-1;

  cout << res+2 << endl;

  return 0;
}