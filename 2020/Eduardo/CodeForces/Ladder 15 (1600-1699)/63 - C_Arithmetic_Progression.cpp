#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100100
using namespace std;

int v[MAXN];
set<int> diffs;
vector<int> res;
int n;

void tryR(int r){
  bool f = true;
  int c=0;
  int val=-1;  
  for(int i=0;i<n-1;i++){
    if(v[i]+r != v[i+1]){
      val = v[i]+r;
      if(val + r != v[i+1]) f=false;
      c++;
    }
    if(v[i]+r > v[i+1]) f=false;
  }

  if(!f || c > 1) return;

  if(c == 1){
    res.push_back(val);
  }else if(c == 0){
    res.push_back(v[0]-r);
    if(r != 0)res.push_back(v[n-1]+r);
  }
}

int main(){

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>v[i];
  }

  sort(v,v+n);

  int r=-1;

  for(int i=1; i<n; i++){
    int d = v[i]-v[i-1];
    if(diffs.count(d) != 0){
      r=d;
      break;
    }
    diffs.insert(d);
  }

  if(n == 1) cout << -1;
  else{
    
    if(r == -1){
      for(set<int>::iterator it = diffs.begin(); it!= diffs.end(); it++){
        tryR(*it);
      }

      if(diffs.size() == 1){
        int d = *diffs.begin();
        if(d && d % 2 == 0) tryR(d/2);
      }
    }else{
      tryR(r);
    }

    sort(res.begin(),res.end());
    cout << res.size() << endl;
    if(res.size()) cout << res[0];
    for(int i=1; i<res.size(); i++){
      cout << " " << res[i];
    }

  }
  
  return 0;
}

