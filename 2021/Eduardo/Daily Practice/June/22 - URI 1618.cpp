#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  while(n--){
    int ax, ay, bx, by, cx, cy, dx, dy, x, y;

    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy>>x>>y;

    cout << (x >= ax && x <= cx && y >=ay && y <= cy ? 1 : 0) << endl;
  }

  return 0;
}