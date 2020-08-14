#include<bits/stdc++.h>
using namespace std;

int fact(int n){
  if(n == 0) return 1;
  return n*fact(n-1);
}

int main(){
  string a,b;

  cin>>a>>b;

  int n=0,m=0,qtd=0;

  for(int i=0; i<a.length(); i++){
    n += a[i] == '+' ? 1 : -1;
    if(b[i] != '?')
      m += b[i] == '+' ? 1 : -1;
    else
      qtd++;
  }

  int x=0, y=0;

  x = (qtd+n-m)/2;
  y = qtd-x;

  if(x < 0 || y < 0)
    printf("%.12lf",0.0);
  else{
    double perm = fact(qtd)/(fact(x)*fact(y));
    double res = perm/(1<<qtd);
    printf("%.12f\n",res);

  }


  return 0;
}