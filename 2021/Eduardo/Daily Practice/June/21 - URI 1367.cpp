#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

map<char, int> inc;

int main(){
  int n;

  while(cin>>n && n){
    char c;
    int t;
    string s;
    inc.clear();

    getchar();

    int q=0,res=0;

    for(int i=0; i<n; i++){
      cin>>c>>t>>s;

      if(s == "incorrect")
        inc[c]++;
      else{
        q++;
        res += t + 20*inc[c];
      }
    }

    cout << q << " " << res << endl;

  }


  
  return 0;
}