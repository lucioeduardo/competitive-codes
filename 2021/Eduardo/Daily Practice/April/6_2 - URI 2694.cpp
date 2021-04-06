#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s;

  int n;
  cin>>n;

  

  while(n--){
    string at="";
    int res=0;

    cin>>s;

    for(int i=0; i<s.length(); i++){
      if(isdigit(s[i])){
        at += s[i];
      }else{
        if(!at.empty())
          res += stoi(at);
        at="";
      }
    }
    if(!at.empty()) res += stoi(at);
    
    cout << res << endl;

  }

  
  return 0;
}