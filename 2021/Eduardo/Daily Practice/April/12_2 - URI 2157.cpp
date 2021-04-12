#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int a,b;

  int n;
  cin>>n;

  while (n--){
    cin>>a>>b;

    string s = "";
    
    for(int i=a; i<=b; i++){
      s += to_string(i);
    }

    string s2 = s;
    reverse(s2.begin(),s2.end());

    s+= s2;

    cout << s << endl;
  }
  


  return 0;
}