#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1000010
using namespace std;

int v[MAXN], tree[MAXN], fl[MAXN], fr[MAXN], cnt[MAXN], n;
map<int,int> val;

void add(int idx, int v){
  while(idx <= n){
    tree[idx] += v;
    idx += idx&-idx;
  }
}

int sum(int idx){
  int res=0;
  while(idx > 0){
    res += tree[idx];
    idx -= idx&-idx;
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;

  for(int i=1; i<=n; i++) cin>>v[i];

  int it=1;

  for(int i=1;i<=n;i++){
    int x = v[i];
    if(!val.count(x)) val[x] = it++;
    
    v[i] = val[x];
    cnt[v[i]]++;
    fl[i] = cnt[v[i]];
    //cout << v[i] << endl;
  }

  ll res=0;
  init(cnt, 0);

  for(int i=n; i>0; i--){
    int x = v[i];
    cnt[x]++;

    fr[i] = cnt[x];

    if(i < n) res += sum(fl[i]-1);
    
    add(fr[i], 1);
  }

  cout << res << endl;

  return 0;
}