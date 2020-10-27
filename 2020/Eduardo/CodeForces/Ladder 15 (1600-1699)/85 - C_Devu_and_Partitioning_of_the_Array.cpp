#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXK 100100
using namespace std;

vector<int> parts[MAXK], even, odd;

int main(){
  int n,k,p;

  cin>>n>>k>>p;
  
  for(int i=0; i<n; i++){
    int v;
    cin>>v;

    if(v%2) odd.push_back(v);
    else even.push_back(v);
  }

  int o = k-p;

  int qO=odd.size(), qE=even.size();

  //cout << qE << " " << o << " " << qO << " " << p << endl;

  if(qO < o || (qO-o)%2 || qE+(qO-o)/2 < p) cout << "NO" << endl;
  else{
    cout << "YES" << endl;
    int itO=0, itE=0;

    for(int i=0; i<p; i++){
      if(itE < qE) parts[i].push_back(even[itE++]);
      else{
        parts[i].push_back(odd[itO++]);
        parts[i].push_back(odd[itO++]);
      }
    }

    for(int i=p; i<k; i++){
      parts[i].push_back(odd[itO++]);
    }

    while(itO < qO) parts[min(p,k-1)].push_back(odd[itO++]);
    while(itE < qE) parts[0].push_back(even[itE++]);

    for(int i=0; i<k; i++){
      cout << parts[i].size();
      for(int j=0; j<parts[i].size(); j++)
        cout << " " << parts[i][j];
      cout << endl;
    }
  }

  return 0;
}