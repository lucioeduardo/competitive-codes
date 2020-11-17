#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

struct segtree{
  int size;
  vector<int> tree;

  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    tree.assign(2*size, 0);
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

    tree[x] = tree[left] + tree[right];
  }

  void build(vector<int>& v){
    build(v,0,0,size);
  }

  void set(int i, int x, int l , int r){
    if(r - l  == 1){
      tree[x] = !tree[x];
      return;
    }

    int m = (l+r)/2;
    int left = x*2+1 , right = x*2+2;

    if(i < m){
      set(i,left,l,m);
    }else{
      set(i,right,m,r);
    }

    tree[x] = tree[left] + tree[right];
  }

  void set(int i){
    set(i, 0, 0, size);
  }

  ll kth(int k, int x, int l, int r){    
    if((l == r-1))
      return l;

    int m = (l+r)/2;

    int left = x*2+1 , right = x*2+2; 
    
    if(tree[left] >= k)
      return kth(k, x*2 + 1, l, m);
    
    return kth(k-tree[left], x*2 + 2, m, r);
  }

  ll kth(int k){
    return kth(k+1 ,0, 0, size);
  }
};

int main(){
  int n,m;

  cin>>n>>m;
  segtree st;
  st.init(n);

  vector<int> v(n);


  for(int i=0;i<n; i++){
    cin>>v[i];
  }

  st.build(v);

  for(int i=0; i<m; i++){
    int t,k;
    cin>>t>>k;

    if(t == 1){
      st.set(k);
    }else{
      cout << st.kth(k) << endl;
    }
  }

  return 0;
}