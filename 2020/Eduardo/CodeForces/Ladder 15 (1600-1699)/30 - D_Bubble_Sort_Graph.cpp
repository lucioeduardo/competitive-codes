#include<bits/stdc++.h>
using namespace std;

vector<int> q;


int main(){
  int n;
  cin>>n;

  for(int i=0; i<n; i++){
    int v;
    cin>>v;
    vector<int>::iterator it = upper_bound(q.begin(), q.end(), v);

    if(it == q.end()) q.push_back(v);
    else *it = v;
  }

  cout << q.size() << endl;
  
  return 0;
}