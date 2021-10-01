#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  while(n--){
    string s;

    cin>>s;

    if(s == "P=NP") cout << "skipped" << endl;
    else{
      int idx;

      for(int i=0; i<s.length(); i++){
        if(s[i] == '+') idx=i;
      }

      string a=s.substr(0,idx), b=s.substr(idx+1, s.length()-idx);

      cout << stoi(a)+stoi(b) << endl;
    }
  }
  
  return 0;
}