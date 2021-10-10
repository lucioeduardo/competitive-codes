#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 550
using namespace std;

struct node{
  int left, right, value;
};

node nodes[MAXN];
int top=-1;

int insert(int idx, int p){
  if(p == -1) return idx;
  else{
    if(nodes[idx].value > nodes[p].value){
      nodes[p].right = insert(idx, nodes[p].right);
    }else{
      nodes[p].left = insert(idx, nodes[p].left);
    }
  }

  return p;
}

int main(){
  int t;

  cin>>t;

  for(int c=1; c<=t; c++){
    int n;

    cin>>n;

    top = -1;

    for(int i=0;i<n;i++){
      int v;
      cin>>v;

      node no = {-1,-1,v};

      nodes[i]=no;

      top = insert(i, top);
    }

    queue<int> q;

    q.push(top);

    cout << "Case " << c << ":" << endl;
    bool f=false;

    while(!q.empty()){
      int val = q.front(); q.pop();

      if(f) cout << ' ';
      f=true;
      cout << nodes[val].value;

      int left = nodes[val].left;
      int right = nodes[val].right;

      if(left != -1) q.push(left);
      if(right != -1) q.push(right);
    }

    cout << endl << endl;
  }
  
  return 0;
}