#include<bits/stdc++.h>
using namespace std;

int main(){
  int nums[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};
  
  int n;

  bool flag=false;

  cin>>n;

  for(int num: nums){
    if(n % num == 0)
      flag = true;
  }

  cout << (flag ? "YES" : "NO") << endl;

  return 0;
}