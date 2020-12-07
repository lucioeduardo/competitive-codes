#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 200020
using namespace std;

int v[MAXN];

int main(){
  int t;
  map<int,int> q;

  cin>>t;

  while(t--){
    int n;
    cin>>n;
    q.clear();

    bool f = true;

    for(int i=0; i<n; i++){
      cin>>v[i];

      if(i>0 && v[i]!=v[i-1])
        f=false;

      if(q[v[i]] == 0)
        q[v[i]]=2;
      else if(v[i] != v[i-1])
        q[v[i]]++;
    }

    q[v[0]]--;
    q[v[n-1]]--;

    int res=999999999;

    for(int i=0; i<n; i++){
      res = min(res, q[v[i]]);
    }

    cout << (f ? 0 : res) << endl;
  }
  
  return 0;
}