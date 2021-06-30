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

    string res = "";

    for(char c: s){
      if(!isupper(c)){
        res += c;
      }
    }

    reverse(res.begin(),res.end());

    cout << res << endl;
  }

  return 0;
}