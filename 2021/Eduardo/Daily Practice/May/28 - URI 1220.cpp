#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1010
using namespace std;

double v[MAXN];

int main(){
  int n;

  while(cin>>n && n){
    double sum=0;
    
    for(int i=0; i<n; i++){
      int d,r;

      scanf("%d.%d",&d,&r);
      
      v[i] = d*100+r;

      sum += v[i]/n;
    }

    double a=0,b=0;

    double res = 0;

    for(int i=0; i<n; i++){
      if(v[i] < sum){
        a += ((int)(sum-v[i]))/100.0;      
      }else{
        b += ((int)(v[i]-sum))/100.0; 
      }
    }

    printf("$%.2f\n",max(a,b));
  }
  
  return 0;
}