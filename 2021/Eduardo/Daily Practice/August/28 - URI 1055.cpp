#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 55
using namespace std;

int v[MAXN];



int main(){
  int t;

  cin>>t;

  for(int i=1; i<=t; i++){
    int n;
    cin>>n;

    for(int j=0; j<n; j++){
      cin>>v[j];
    }

    sort(v,v+n);

    int l = v[n-1];
    int r = l;

    int res=0;

    int min_v = 0, max_v=n-2;
    bool f = true;

    while(min_v <= max_v){
      int min_test = max(abs(l-v[min_v]), abs(r-v[min_v]));
      int max_test = max(abs(l-v[max_v]), abs(r-v[max_v]));

      f = (min_test > max_test);
      
      int value;

      if(f){
        value = v[min_v++];
      }else{
        value = v[max_v--];
      }

      if(abs(value-l) > abs(value-r)){
        res += abs(value-l);
        l=value;
      }else{
        res += abs(value-r);
        r=value;
      }
    }

    printf("Case %d: %d\n",i,res);
  }


  
  return 0;
}