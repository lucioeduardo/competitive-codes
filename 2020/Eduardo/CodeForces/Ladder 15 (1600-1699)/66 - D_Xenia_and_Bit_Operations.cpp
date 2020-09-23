#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 150000
using namespace std;

int tree[4*MAXN], v[MAXN];

int build(int x, int l, int r){
  if(l == r){
    tree[x] = v[l];
    return 1;
  }else{
    int m = (l+r)/2;
    int esq = build(x*2,l,m);
    build(x*2+1,m+1,r);
  
    if(esq % 2){
      tree[x] = tree[x*2] | tree[x*2+1];
    }else{
      tree[x] = tree[x*2] ^ tree[x*2+1];
    }
    return esq+1;
  } 
}

int update(int x, int l, int r, int idx, int value){
  if(l == r){
    tree[x] = value;
    return 1;
  }else{
    int m = (l+r)/2;
    int ret=1;

    if(idx <= m){
      ret = update(x*2,l,m,idx,value);
    }
    else{
      ret = update(x*2+1,m+1,r,idx,value);
    }
    
    if(ret % 2) tree[x] = tree[x*2] | tree[x*2+1];
    else tree[x] = tree[x*2] ^ tree[x*2+1];

    return ret+1;
  }
}


int main(){
  int n,m;

  cin>>n>>m;

  for(int i=1; i<=(1<<n); i++){
    cin>>v[i];
  }

  build(1,1,1<<n);

  for(int i=0; i<m; i++){
    int a,b;
    cin>>a>>b;
    update(1,1,1<<n,a,b);

    cout << tree[1] << endl;
  }
  
  return 0;
}