#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100100
using namespace std;

int a[MAXN], b[MAXN];

int main(){
  int n;

  cin>>n;

  for(int i=0; i<n; i++)
    cin>>a[i];

  for(int i=0; i<n; i++)
    cin>>b[i];

  sort(a,a+n);
  sort(b,b+n);

  int rB=n-1, rA=n-1;
  int res=0;

  while(rA >= 0 && rB >= 0){
    int v = b[rB];

    while(rA>0 && v <= a[rA])
      rA--;
    
    if(rA >=0 && v > a[rA]){ 
      rA--;
      res++;
    }
    rB--;
  }

  cout << res << endl;
  
  return 0;
}