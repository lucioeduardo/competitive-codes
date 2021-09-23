#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

vector<int> v;

int main(){
  int n;

  cin>>n;

  while(n--){
    int m;
    v.clear();

    cin>>m;

    for(int i=0; i<m; i++){
      int x;
      cin>>x;

      if(x%2) v.push_back(x);
    }

    int l=0, r=v.size()-1;

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
      //cout << i;

      if(i%2){
        cout << v[l++];
      }else{
        cout<< v[r--];
      }

      if(l <= r) cout << ' ';
    }

    cout << endl;

  }
  
  return 0;
}