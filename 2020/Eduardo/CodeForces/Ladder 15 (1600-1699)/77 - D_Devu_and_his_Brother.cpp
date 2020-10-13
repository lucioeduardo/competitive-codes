#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100100
using namespace std;

int a[MAXN],b[MAXN];

bool compare(int a, int b){
  return a>b;
}

int main(){
  int n,m;

  cin>>n>>m;

  for(int i=0; i<n; i++) cin>>a[i];
  for(int i=0; i<m; i++) cin>>b[i];

  sort(a, a+n);
  sort(b, b+m,compare);

  ll res=0;

  for(int i=0; i<min(m,n) && a[i] < b[i]; i++){
    res += (b[i]-a[i]);
  }

  cout << res << endl;


  
  return 0;
}