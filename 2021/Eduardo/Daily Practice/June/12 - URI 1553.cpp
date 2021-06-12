#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define pii pair<int,int>
using namespace std;

int main(){
  int n,k;
  map<int,int> freq;

  while(cin>>n>>k && n>0){
    freq.clear();

    for(int i=0; i<n; i++){
      int v;
      cin>>v;
      freq[v]++;
    }

    int res=0;

    for(pii p: freq){
      if(p.second >= k) res++;
    }

    cout << res << endl;
  }
  
  return 0;
}