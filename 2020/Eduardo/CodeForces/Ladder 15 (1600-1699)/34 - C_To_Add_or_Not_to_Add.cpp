#include<bits/stdc++.h>
#define ll long long
#define MAXN 100100
using namespace std;

ll v[MAXN], sum[MAXN];

int main(){
  int n,k;

  cin>>n>>k;

  for(int i=0; i<n; i++){
    cin>>v[i];
  }

  sort(v,v+n);

  sum[0] = v[0];
  for(int i=1; i<n; i++){
    sum[i] = sum[i-1] + v[i];
  }

  ll res=0, a=-1;

  for(int i=0; i<n; i++){
    int esq=0, dir = i+1;

    int qtd=0;

    while(esq <= dir){
      ll meio = (esq+dir)/2;

      if(meio*v[i] - (sum[i] - sum[i-(meio)]) <= k){
        qtd=meio;
        esq=meio+1;
      }else{
        dir=meio-1;
      }
    }

    if(qtd > res){
      res = qtd;
      a=i;
    }
  }


  cout << res << " " << v[a] << endl;
  
  return 0;
}