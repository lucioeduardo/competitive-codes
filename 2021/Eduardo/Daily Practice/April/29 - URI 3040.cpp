#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  for(int i=0; i<n; i++){
    int a,d,g;

    scanf("%d %d %d",&a,&d,&g);

    bool res=true;

    if(a < 200 || a > 300) res=false;
    if(d < 50) res=false;
    if(g < 150) res=false;

    

    cout << (res ? "Sim":"Nao") << endl;
  }
  
  return 0;
}