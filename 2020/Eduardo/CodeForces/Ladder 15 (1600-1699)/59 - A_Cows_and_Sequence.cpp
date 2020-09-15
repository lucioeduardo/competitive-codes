#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 200200
using namespace std;

double add[MAXN];

int main(){

  int n;
  cin>>n;
  
  double sum = 0;
  ll qtd=1;
  double ad=0;


  while(n--){
    int t,a;
    double x;
    scanf("%d",&t);

    if(t == 1){
      scanf("%d %lf",&a,&x);
      add[a]+=x;
      sum+=x*a;
    }else if(t == 2){
      scanf("%lf",&x);
      qtd++;
      add[qtd-1] -= x;
      add[qtd] = x;
      sum+=x;
    }else{
      add[qtd-1] += add[qtd];
      sum -= add[qtd];
      add[qtd]=0;
      qtd--;
    }

    double avg = sum/(double)qtd;

    printf("%.6lf\n",avg);
  }
  return 0;
}