#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100010
#define pii pair<int,int>
using namespace std;

int m[MAXN];
vector<pii> edges, d;

int main(){
  int n,k;

  cin>>n>>k;

  for(int i=1; i<=n; i++){
    int x;
    cin>>x;

    d.push_back({x,i});
  }

  sort(d.begin(), d.end());

  int left=-1;
  bool flag=true;

  if(d[0].first != 0) flag=false;

  for(int i=0; i<n && flag; i++){
    if(d[i].first == 0){
      if(left == -1) left++;
      else flag=false;
    }else{
      while(d[left].first < d[i].first-1) left++;
      if(m[left] == k) left++;
      
      if(d[left].first >= d[i].first) flag=false;
      else{
        edges.push_back({d[left].second, d[i].second});
        m[left]++;
        m[i]++;
      }
    }
  }

  if(!flag) cout << -1 << endl;
  else{
    cout << edges.size() << endl;
    for(int i=0; i<edges.size(); i++){
      cout << edges[i].first << " " << edges[i].second << endl;
    }
  }

  return 0;
}