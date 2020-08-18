#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;

  vector<ll> values;

  int it=1;

  for(int i=0; i<n; i++){
    ll v;
    cin>>v;

    values.push_back(v);
  }

  ll res=0;

  sort(values.begin(), values.end());

  for(int i=0;i<n; i++){
    res += abs(values[i]-it);
    it++;
  }

  cout << res << endl;

  return 0;
}