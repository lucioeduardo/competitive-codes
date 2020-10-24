#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXM 5050
using namespace std;

bool check(int v){
  bool d[10];
  for(int i=0; i<10; i++)d[i]=false;

  while(v > 0){
    int x = v%10;
    if(d[x]) return false;
    d[x]=true;

    v/=10;
  }

  return true;
}

int sum[MAXM];

int main(){
  int n,m; 

  sum[0]=0;

  for(int i=1; i<=5050; i++){
    sum[i] = check(i) + sum[i-1];
  }

  while(cin>>n>>m){
    cout << sum[m] - sum[n-1] << endl;
  }



  return 0;
}