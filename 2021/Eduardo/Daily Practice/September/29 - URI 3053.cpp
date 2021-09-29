#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;
  char pos;

  cin>>n>>pos;

  int a=(pos == 'A'), b=(pos == 'B'), c=(pos == 'C');

  while(n--){
    int x;
    cin>>x;

    if(x == 1){
      swap(a,b);
    }else if(x == 2){
      swap(b,c);
    }else{
      swap(a,c);
    }

  }

  if(a) cout << "A" << endl;
  if(b) cout << "B" << endl;
  if(c) cout << "C" << endl;
  
  return 0;
}