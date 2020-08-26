#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;

int v[MAXN], seq[MAXN], n;



int main(){
  cin>>n;

  for(int i=0; i<n; i++){
    cin>>v[i];
  }

  seq[n-1]=1;

  for(int i=n-2; i>=0 ; i--){
    if(v[i] < v[i+1])
      seq[i] = seq[i+1]+1;
    else
      seq[i]=1;
  }

  int res=1;

  for(int i=0; i<n; i++){
    res = max(res,seq[i]);
    if(i > 0 || seq[i] < n)
      res = max(res, seq[i]+1);
    if(v[i+seq[i]+1] > v[i+seq[i]-1]+1)
      res = max(res, seq[i] + 1 + seq[i+seq[i]+1]);
    if(v[i+seq[i]] > v[i+seq[i]-2]+1)
      res = max(res, seq[i] + seq[i+seq[i]]);
  }

  cout << res << endl;

  return 0;
}