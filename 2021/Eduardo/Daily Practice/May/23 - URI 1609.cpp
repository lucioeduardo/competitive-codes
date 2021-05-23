#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int t;
  set<int> c;

  cin>>t;

  while(t--){
    int n;
    cin>>n;
    c.clear();


    while(n--){
      int v;
      cin>>v;

      c.insert(v);
    }

    cout << c.size() << endl;
  }
  
  return 0;
}