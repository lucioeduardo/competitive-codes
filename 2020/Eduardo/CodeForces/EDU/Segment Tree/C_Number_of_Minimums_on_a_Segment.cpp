#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define pli pair<ll,int>
using namespace std;

struct segtree{
  int size;
  vector<pli> mins;

  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    mins.assign(2*size, {0LL,0});
  }

  void build(vector<int>&v, int x, int l, int r){
    if(r - l  == 1){
      if(l < v.size()) mins[x] = {v[l],1};
      return;
    }

    int m = (l+r)/2;
    int left = x*2+1;
    int right = x*2+2;

    build(v,left,l,m);
    build(v,right,m,r);

    mins[x] = min(mins[left],mins[right]);
    if(mins[left].first == mins[right].first)
      mins[x].second = mins[left].second + mins[right].second;
  }

  void build(vector<int>& v){
    build(v,0,0,size);
  }

  void set(int i, int x, int v, int l , int r){
    if(r - l  == 1){
      mins[x] = {v,1};
      return;
    }

    int m = (l+r)/2;
    int left = x*2+1 , right = x*2+2;

    if(i < m){
      set(i,left,v,l,m);
    }else{
      set(i,right,v,m,r);
    }

    mins[x] = min(mins[left],mins[right]);
    if(mins[left].first == mins[right].first)
      mins[x].second = mins[left].second + mins[right].second;
  }

  void set(int i, int v){
    set(i, 0, v, 0, size);
  }

  pli min_v(int a, int b, int x, int l, int r){
    if(l >= a && r <= b)
      return mins[x];

    if(r <= a || l >= b)
      return {LLONG_MAX,1};

    int m = (l+r)/2;
    
    pli s1 = min_v(a, b, x*2 + 1, l, m);
    pli s2 = min_v(a, b, x*2 + 2, m, r);

    pli res = min(s1,s2);
    if(s1.first == s2.first)
      res.second = s1.second + s2.second;
    
    return res;
  }

  pli min_v(int a, int b){
    return min_v(a, b, 0, 0, size);
  }
};

int main(){
  int n,m;

  cin>>n>>m;

  vector<int> v(n);
  segtree st;
  st.init(n);

  for(int i=0; i<n; i++){
    cin>>v[i];
  }

  st.build(v);

  while(m--){
    int t;
    cin>>t;

    if(t == 1){
      int i,v;
      cin>>i>>v;

      st.set(i,v);
    }else{
      int l,r;
      cin>>l>>r;
      
      pli res = st.min_v(l,r);

      cout << res.first << " " << res.second << endl;
    }
  }

  return 0;
}