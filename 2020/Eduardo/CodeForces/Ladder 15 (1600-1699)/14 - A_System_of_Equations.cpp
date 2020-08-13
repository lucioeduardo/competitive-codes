#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;

  cin>>n>>m;

  int maxA = sqrt(n)+1;
  
  int res=0;

  for(int i=0; i<=maxA; i++){
    int b = n - (i*i);

    if(b >= 0 && i + b*b == m)
      res++;
  }

  cout << res;

  return 0;
}