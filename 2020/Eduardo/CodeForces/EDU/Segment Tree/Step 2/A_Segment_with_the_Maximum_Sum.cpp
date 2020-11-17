#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

struct node{
  ll sum, pref, suf, res;
};

struct segtree{
  int size;
  vector<node> tree;

  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    tree.assign(2*size, {0LL,0LL,0LL,0LL});
  }

  void update(int x, int left, int right){
    tree[x].sum = tree[left].sum + tree[right].sum;
    tree[x].pref = max(tree[left].sum + tree[right].pref, tree[left].pref);
    tree[x].suf = max(tree[right].sum + tree[left].suf, tree[right].suf);
    tree[x].res = max(tree[left].suf + tree[right].pref,max(tree[left].res, tree[right].res));
  }

  void build(vector<int>&v, int x, int l, int r){
    if(r - l  == 1){
      
      if(l < v.size()){ 
        int k = max(v[l],0);
        tree[x] = {v[l],k,k,k};
      }
      return;
    }

    int m = (l+r)/2;
    int left = x*2+1;
    int right = x*2+2;

    build(v,left,l,m);
    build(v,right,m,r);

    update(x,left,right);
  }

  void build(vector<int>& v){
    build(v,0,0,size);
  }

  void set(int i, int x, int v, int l , int r){
    if(r - l  == 1){
      int k = max(v,0);
      tree[x] = {v,k,k,k};
      return;
    }

    int m = (l+r)/2;
    int left = x*2+1 , right = x*2+2;

    if(i < m){
      set(i,left,v,l,m);
    }else{
      set(i,right,v,m,r);
    }

    update(x,left,right);
  }

  void set(int i, int v){
    set(i, 0, v, 0, size);
  }

  ll maxSegment(){
    return tree[0].res;
  }
};


int main(){
  int n,m;

  cin>>n>>m;

  vector<int> v(n);
  segtree tree;
  tree.init(n);

  for(int i=0; i<n; i++){
    cin>>v[i];
  }

  tree.build(v);
  cout << tree.maxSegment() << endl;

  for(int j=0; j<m; j++){
    int i,v;
    cin>>i>>v;

    tree.set(i,v);
    cout << tree.maxSegment() << endl;
  }

  

  return 0;
}