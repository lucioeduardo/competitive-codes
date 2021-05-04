#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

int p[MAXN];
int n,c,f;

bool check(int x){
  int q=1;
  int sum=0;

  for(int i=0; i<n; i++){
    if(p[i] > x) return false;

    if(sum + p[i] > x){
      q++;
      sum = 0;
    }

    sum += p[i];
  }

  return (q <= c);
}

int main(){
  int t;

  cin>>t;

  while(t--){
    

    cin>>n>>c>>f;

    int l=0, r=0;

    for(int i=0; i<n; i++){
      cin>>p[i];
      r+=p[i];
    }

    int res=-1;

    while(l <= r){
      int m = (l+r)/2;

      if(check(m)){
        res=m;
        r=m-1;
      }else{
        l=m+1;
      }
    }

    printf("%d $%d\n", res, res*c*f);

  }

  return 0;
}