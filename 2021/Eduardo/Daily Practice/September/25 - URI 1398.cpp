#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;
#define M 131071

ll fast_pow(int n){
  if(n == 0) return 1;

  if(n % 2 == 0){
    ll v = fast_pow(n/2);
    return (v*v)%M;
  }else{
    return (2*fast_pow(n-1))%M;
  }
}

int res(string num){
  int r = num.length()-2;
  int p = 0;
  int res=0;

  for(int i=r; i>=0; i--){
    if(num[i] == '1') res = (res + fast_pow(p))%M;


    p++;
  }

  return res;
}



int main(){
  string num="", act;

  while(cin>>act){
    num += act;

    if(act[act.length()-1] == '#'){
      int val = res(num);
      cout << (val == 0 ? "YES":"NO") << endl;

      num = "";
    }
  }
  
  return 0;
}