#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 200200 
using namespace std;

ll bit[MAXN], n, nums[MAXN], qtd[MAXN];

void add(int x, ll v){
  while(x <= n){
    bit[x] += v;
    x += (x&-x);
  }
}

ll sum(int x){
  ll res=0;

  while(x > 0){
    res += bit[x];
    x -= (x&-x);
  }

  return res;
}

int main(){
  int q;

  cin>>n>>q;


  for(int i=0; i<n; i++){
    cin>>nums[i];
  }

  for(int i=0; i<q; i++){
    int a,b;
    cin>>a>>b;

    add(a,1);
    add(b+1,-1);
  }

  for(int i=1;i<=n;i++){
    qtd[i-1] = sum(i);
  }

  sort(nums,nums+n);
  sort(qtd,qtd+n);

  ll res=0;

  for(int i=0;i<n;i++){
    res += nums[i]*qtd[i];
  }

  cout << res << endl;

  return 0;
}