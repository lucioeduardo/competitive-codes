#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

bool check(int v){
  bool used[10];
  memset(used,false,sizeof(used));

  while(v>0){
    int x = v%10;
    if(used[x]) return false;

    used[x]=true;
    v /= 10;
  }

  return true;
}

int main(){
  int a,b;

  while(cin>>a>>b){
    int res=0;

    for(int i=a; i<=b; i++){
      if(check(i)) res++;
    }

    cout << res << endl;
  }
  
  return 0;
}