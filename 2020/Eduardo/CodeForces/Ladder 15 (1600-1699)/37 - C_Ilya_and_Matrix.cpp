#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> v;

int main(){
  int n;

  cin>>n;
  v.resize(n);

  for(int i=0; i<n; i++){
    scanf("%d",&v[i]);
  }

  sort(v.begin(), v.end());

  ll mult= log2(n)/2 +1;
  ll it=1, q=1;

  ll res=0;

  for(int i=n-1; i>=0; i--){
    res += v[i]*mult;

    it--;

    if(mult > 1 && !it){
      int ant=q;
      q*=4;
      it=q-ant;
      mult--;
    }
  }
  
  cout << res << endl;

  return 0;
}