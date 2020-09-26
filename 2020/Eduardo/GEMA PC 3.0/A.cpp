#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int t, tr[3], q[3], v[3];

bool solve(int idx){
  if(idx >= 3) return true;
  if(tr[idx] < 0) return false;
  if(tr[idx] == 0) return solve(idx+1);

  bool res=false;

  for(int i=0; i<3; i++){
    int aux = q[i];
    int troco = tr[idx];

    while(q[i]){
      tr[idx]-=v[i];
      q[i]--;
      res = res || solve(idx);
    }

    q[i]=aux;
    tr[idx]=troco;
  }

  return res;
}

int main(){

  cin>>t;

  while (t--)
  {
    for(int i=0; i<3; i++) cin>>tr[i];

    for(int i=0; i<3; i++) cin>>q[i]>>v[i];

    cout << (solve(0) ? "Yes":"No") << endl;
  }
  

  return 0;
}