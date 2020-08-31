#include<bits/stdc++.h>
using namespace std;

int main(){
  string a, b;

  cin>>a>>b;

  if(a.length() != b.length()){
    cout << "NO" << endl;
    return 0;
  }

  bool a_one=false, b_one=false;

  for(int i=0; i<a.length(); i++){
    if(a[i] == '1') a_one=true;
    if(b[i] == '1') b_one=true;
  }

  if(a_one != b_one) cout << "NO" << endl;
  else cout << "YES" << endl;

  return 0;
}

//00,10,11