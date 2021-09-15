#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

stack<string> st;

int main(){
  int n;

  cin>>n;
  getchar();
  
  int res=0;

  while(n--){
    if(st.empty()) st.push("ECAF");
    
    string s;

    for(int i=0; i<4; i++){
      char c;
      cin>>c;

      s += c;
    }

    if(st.top() == s){
      res++;
      st.pop();
    }else{
      reverse(s.begin(), s.end());
      st.push(s);
    }
  }

  cout << res << endl;
  
  return 0;
}