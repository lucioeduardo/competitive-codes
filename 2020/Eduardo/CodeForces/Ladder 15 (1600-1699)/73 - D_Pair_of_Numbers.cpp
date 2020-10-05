#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 300300
using namespace std;

int v[MAXN], q[MAXN], res=0;

int main(){
  int n;

  cin>>n;

  for(int i=1; i<=n; i++){
    cin>>v[i];
  }

  for(int i=1; i<=n; i++){
    int l=i, r=i;

    while(l>1 && v[l-1]%v[i] == 0) l--;
    while(r<n && v[r+1]%v[i] == 0) r++;

    i=r;

    q[l] = max(q[l], r-l);
    //cout << i << " " << q[i] << endl;
    res = max(res,r-l);
  }

  int num=0;
  for(int i=1; i<=n; i++){
    if(q[i] == res) num++;
  }

  cout << num << " " << res << endl;

  bool f = true;
  for(int i=1; i<=n; i++){

    if(q[i] == res) {
      if(!f) cout << ' ';
      else f=false;
      
      cout << i;
    }
  }

  cout << endl;

  return 0;
}