#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 55
using namespace std;

struct node{
  char value;
  int left, right;
};

node nodes[MAXN];

int top=-1, num=-1;

int solve(string prefixo, string infixo){
  node node = {prefixo[0], -1, -1};
  
  int idx=0;

  for(int i=0; i<infixo.size(); i++){
    if(infixo[i] == prefixo[0]) idx=i;
  }

  int len = infixo.size();
  
  if(idx > 0)
    node.left = solve(prefixo.substr(1,idx), infixo.substr(0,idx));
  
  if(len-idx-1 > 0)
    node.right = solve(prefixo.substr(idx+1,len-idx-1), infixo.substr(idx+1,len-idx-1));
  nodes[++num] = node;

  return num;
}

string posfixo(int raiz){
  string res = "";

  if(raiz == -1) return "";

  res += posfixo(nodes[raiz].left);
  res += posfixo(nodes[raiz].right);
  res += nodes[raiz].value;

  return res;
}

int main(){
  int c,k;

  cin>>c;

  while(c--){
    string prefixo, infixo;

    cin>> k >> prefixo>> infixo;
    num=-1;
    int raiz = solve(prefixo, infixo);
    
    cout << posfixo(raiz) << endl;
  }
  
  return 0;
}