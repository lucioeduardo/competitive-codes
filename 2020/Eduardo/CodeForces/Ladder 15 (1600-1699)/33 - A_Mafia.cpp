#include<bits/stdc++.h>
#define ll long long
#define MAXN 100100
using namespace std;

ll v[MAXN];

int main(){
  int n;

  cin>>n;

  ll max_v=0, sum=0;

  for(int i=0; i<n; i++){
    cin>>v[i];

    max_v = max(max_v,v[i]);
  }

  for(int i=0; i<n; i++){
    sum += max_v - v[i];
  }

  if(sum >= max_v) cout << max_v;
  else {
    int res = max_v + (max_v-sum)/(n-1);
    if((max_v-sum) % (n-1)) res++;
    cout << res << endl;
  }



  return 0;
}