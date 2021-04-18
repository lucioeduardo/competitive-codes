#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 10010
using namespace std;

set<int> sA, sB;

int main(){
  int a,b;
  

  while(cin>>a>>b && a){
    sA.clear(); sB.clear();
   
    int v;

    for(int i=0; i<a; i++){
      cin>>v;
      sA.insert(v);

    }

    int qA=0,qB=0;
    
    for(int i=0; i<b; i++){
      cin>>v;

      sB.insert(v);
    }

    for(int x: sA){
      if(sB.find(x) == sB.end())
        qA++;
    }

    for(int x: sB){
      if(sA.find(x) == sA.end())
        qB++;
    }

    cout << min(qA, qB) << endl;
  }

  return 0;
}