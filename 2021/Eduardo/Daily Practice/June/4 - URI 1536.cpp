#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

struct time{
  int gc, gf;
};

int main(){
  int n;
  struct time t1;
  struct time t2;

  cin>>n;

  while(n--){
    scanf("%d x %d",&t1.gc, &t2.gf);
    scanf("%d x %d",&t2.gc, &t1.gf);

    int a = t1.gc + t1.gf, b = t2.gc + t2.gf;

    if(a == b){
      if(t1.gf == t2.gf) cout << "Penaltis";
      else if(t1.gf > t2.gf) cout << "Time 1";
      else cout << "Time 2";
    }else if(a > b){
      cout << "Time 1";
    }else{
      cout << "Time 2";
    }
    cout << endl;
  }
  
  return 0;
}