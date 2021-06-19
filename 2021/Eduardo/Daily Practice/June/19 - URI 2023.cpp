#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

vector<string> names;

bool greaterThan(string a, string b){
  for(int i=0; i<min(a.size(), b.size()); i++){
    if(tolower(a[i]) > tolower(b[i])) return true;
    else if(tolower(a[i]) < tolower(b[i])) return false;
  }

  return a.size() >= b.size();
}

int main(){
  string res = "", str;

  while(getline(cin,str)){
    if(res.empty()) res = str;

    if(greaterThan(str,res))
      res = str;
  }

  cout << res << endl;
  
  return 0;
}