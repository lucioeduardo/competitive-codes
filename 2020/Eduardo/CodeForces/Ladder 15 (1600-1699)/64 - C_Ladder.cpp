#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 100100
#define ll long long
using namespace std;

int a[MAXN], incr[MAXN], decr[MAXN];

int main(){
  int n,m;

  cin>>n>>m;

  for(int i=1; i<=n; i++){
    cin>>a[i];
    incr[i]=decr[i]=i;
  }


  incr[n]=n;
  for(int i=n-1; i>=0; i--){
    if(a[i+1] >= a[i]) incr[i] = incr[i+1];
  }

  decr[1]=1;
  for(int i=2; i<=n; i++){
    if(a[i] <= a[i-1]) decr[i] = decr[i-1];
  }



  for(int i=0; i<m; i++){
    int l,r;
    cin>>l>>r;

    bool flag = false;
    
    if(incr[l] >= r) flag=true;
    if(decr[r] <= l) flag=true;
    if(incr[l] >= decr[r])flag=true;

    cout << (flag ? "Yes":"No") << endl;
  }


  
  return 0;
}