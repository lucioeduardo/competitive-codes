#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

double dist(int x1, int y1, int x2, int y2){
  return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
  int L,C,r1,r2;

  while(cin>>L>>C>>r1>>r2 && L!=0){
    int x1=r1, y1=r1;
    int x2=L-r2, y2= C-r2;

    if(2*max(r1,r2) <= min(L,C) && dist(x1,y1,x2,y2) >= (r1+r2)*(r1+r2)){
      cout << "S" << endl;
    }else{
      cout << "N" << endl;
    }
  }
  
  return 0;
}