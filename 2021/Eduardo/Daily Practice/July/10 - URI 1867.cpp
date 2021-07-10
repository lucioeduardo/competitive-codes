#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;


int val(string n){
  int res=0;
  
  for(char c: n){
    res += (c-'0');
  }
  
  if(res > 9) return val(to_string(res));
  return res;
}

int main(){
  string a,b;

  while(cin>>a>>b && !(a=="0" && b=="0")){
    int x = val(a), y = val(b);

    if(x > y) cout << "1" << endl;
    else if(x < y) cout << "2" << endl;
    else cout << "0" << endl;
  }
  
  return 0;
}