#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s;
  vector<string> v;

  while(cin>>s){
    v.push_back(s);
  }

  sort(v.begin(), v.end());

  for(string str: v){
    cout << str << endl;
  }
  
  return 0;
}