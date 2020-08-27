#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  int n;

  cin>>n;
  v.resize(n);

  for(int i=0; i<n; i++)
    cin>>v[i];
  
  sort(v.begin(),v.end());

  int res=0;

  for(int i=0; i<n; i++){
    int q = upper_bound(v.begin(),v.end(),v[i]*2) - v.begin();
    res = max(res,q-i);
  }

  cout << n-res << endl;
  return 0;
}