#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

struct segtree{
  int size;
  vector<ll> tree;

  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    tree.assign(2*size, 0LL);
  }

  void build(vector<int>&v, int x, int l, int r){
    if(r - l  == 1){
      if(l < v.size()) tree[x] = v[l];
      return;
    }

    int m = (l+r)/2;
    int left = x*2+1;
    int right = x*2+2;

    build(v,left,l,m);
    build(v,right,m,r);

    tree[x] = max(tree[left],tree[right]);
  }

  void build(vector<int>& v){
    build(v,0,0,size);
  }

  void set(int i, int x, int v, int l , int r){
    if(r - l  == 1){
      tree[x] = v;
      return;
    }

    int m = (l+r)/2;
    int left = x*2+1 , right = x*2+2;

    if(i < m){
      set(i,left,v,l,m);
    }else{
      set(i,right,v,m,r);
    }

    tree[x] = max(tree[left],tree[right]);
  }

  void set(int i, int v){
    set(i, 0, v, 0, size);
  }

  int first_above(int x, int l, int r, int k, int y){
    if(r - l == 1){
      return (tree[x] >= k ? l : -1);
    }

    int m = (l+r)/2;
    int left = x*2+1 , right = x*2+2;

    int rl=-1, rr=-1;

    if(tree[left] >= k && m > y)
      rl = first_above(left,l,m,k,y);
    if(rl == -1 && tree[right] >= k)
      rr = first_above(right,m,r,k,y);

    return rl == -1 ? rr : rl;
  }

  ll first_above(int k, int y){
    return first_above(0, 0, size,k, y);
  }
};



int main(){
  int n,m;

  cin>>n>>m;
  segtree st;
  st.init(n);

  vector<int> v(n);

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
      int k,y;
      cin>>k>>y;

      cout << st.first_above(k,y) << endl;
    }
  }

  return 0;
}