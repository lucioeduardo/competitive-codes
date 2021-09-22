#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 10010
using namespace std;
  
int n,m;
int val[MAXN];

bool compare(int a, int b){
  int x = a%m, y=b%m;
  
  if(x ==  y){
    if(abs(a%2) != abs(b%2)){
      return (a%2);
    }else{
      if(a%2 == 0){
        return a<b;
      }else{
        return a>b;
      }
    }
  }
  return x < y;
}

int main(){
  while(cin>>n>>m){
    for(int i=0; i<n; i++){
      cin>>val[i];
    }

    sort(val,val+n,compare);

    cout << n << " " << m << endl;

    for(int i=0; i<n; i++){
      cout << val[i] << endl;
    }
  }
  
  return 0;
}