#include<bits/stdc++.h>
#define MAXM 55
using namespace std;

int nums[MAXM];

int main(){
  int n,m;

  cin>>n>>m;

  for(int i=0; i<m; i++){
    cin>>nums[i];
  }

  int res = 9999999;

  sort(nums, nums+m);

  for(int i=0; i<=m-n; i++){
    res = min(res, nums[i+n-1] - nums[i]);
  }

  cout << res << endl;
  
  return 0;
}