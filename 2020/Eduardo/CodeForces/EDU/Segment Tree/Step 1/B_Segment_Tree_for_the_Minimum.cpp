#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

struct segtree{
  int size;
  vector<ll> mins;

  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    mins.assign(2*size, 0LL);
  }

  void build(vector<int>&v, int x, int l, int r){
    if(r - l  == 1){
      if(l < v.size()) mins[x] = v[l];
      return;
    }

    int m = (l+r)/2;
    int left = x*2+1;
    int right = x*2+2;

    build(v,left,l,m);
    build(v,right,m,r);

    mins[x] = min(mins[left],mins[right]);
  }

  void build(vector<int>& v){
    build(v,0,0,size);
  }

  void set(int i, int x, int v, int l , int r){
    if(r - l  == 1){
      mins[x] = v;
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
  }

  void set(int i, int v){
    set(i, 0, v, 0, size);
  }

  ll min_v(int a, int b, int x, int l, int r){
    if(l >= a && r <= b)
      return mins[x];

    if(r <= a || l >= b)
      return LLONG_MAX;

    int m = (l+r)/2;
    
    ll s1 = min_v(a, b, x*2 + 1, l, m);
    ll s2 = min_v(a, b, x*2 + 2, m, r);

    return min(s1,s2);
  }

  ll min_v(int a, int b){
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
      
      cout << st.min_v(l,r) << endl;
    }
  }

  return 0;
}