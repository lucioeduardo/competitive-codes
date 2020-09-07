#include<bits/stdc++.h>
#define ll long long
using namespace std;

int qtd[10];

bool rem(int r){
  for(int i=1; i<=9; i++){
    if(i % 3 == r && qtd[i] > 0){
      qtd[i]--;
      return true;
    }
  }
  
  return false;
}

int main(){
  int n;

  cin>>n;

  int sum=0;

  bool has0=false;

  for(int i=0; i<n; i++){
    int v;
    cin>>v;

    if(!v) has0 = true;

    qtd[v]++;
  
    sum = (sum+v)%3;
  }

  if(!has0) cout << -1 << endl;
  else{
    if(sum == 1){
      if(!rem(1)){
        rem(2);rem(2);
      }
    }
    else if(sum == 2){ 
      if(!rem(2)){
        rem(1);rem(1);
      }
    }

    bool flag=true;

    for(int i=9; i>=0; i--){
      if(i > 0 && qtd[i]>0) flag=false;

      if(i == 0 && flag)qtd[i]=1;

      while(qtd[i]--) cout<<i;
    }

    cout << endl;
  }
  
  return 0;
}