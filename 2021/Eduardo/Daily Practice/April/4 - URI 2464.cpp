#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string cypher, s;

  cin>>cypher>>s;

  for(int i=0; i<s.size(); i++){
    char c = s[i];
    s[i] = cypher[c-'a'];
  }

  cout << s << endl;

  return 0;
}