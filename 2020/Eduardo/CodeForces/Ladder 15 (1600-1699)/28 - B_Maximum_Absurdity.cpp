#include<bits/stdc++.h>
#define MAXN 200020
#define ll long long
using namespace std;

ll values[MAXN], max_r[MAXN], sum_k[MAXN];

int main(){
  int n,k;

  cin>>n>>k;

  for(int i=0; i<n; i++){
    cin>>values[i];
  }

  for(int i=n-1; i>=0; i--){
    sum_k[i] = sum_k[i+1] + values[i];

    if(i+k < n)
      sum_k[i] -= values[i+k];

    int m = max_r[i+1];

    max_r[i] = sum_k[i] >= sum_k[m] ? i : m;
  }

  int a=0, b=k;

  for(int i=0; i<n-k; i++){
    int m = max_r[i+k];

    ll s = sum_k[i] + sum_k[m];
    ll prev = sum_k[a] + sum_k[b];

    if(s > prev){
      //cout << s << endl;
      a=i;
      b=m;
    }
  }

  cout << a+1 << " " << b+1 << endl;

  return 0;
}