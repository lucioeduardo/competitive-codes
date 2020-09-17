#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1010
#define pii pair<int,int>
using namespace std;

struct request{
  int c,p,i;
};

request requests[MAXN];
pii tables[MAXN];
bool used[MAXN];

bool compare(request a, request b){
  if(a.p == b.p)
    return a.c < b.c;
  return a.p > b.p;
}

bool compPii(pii a, pii b){
  return a.first < b.first;
}

int main(){
  int n;

  cin>>n;

  for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
    requests[i] = {a,b,i+1};
  }

  sort(requests,requests+n,compare);

  int k;
  cin>>k;

  for(int i=0; i<k; i++){
    int v;
    cin>>v;
    tables[i] = {v,i+1};
  }
  
  sort(tables,tables+k, compPii);

  int sum=0;
  vector<pii> res;

  for(int i=0; i<n; i++){
    int c = requests[i].c;
    int p = requests[i].p;

    pii aux = {c,0};

    int idx = lower_bound(tables,tables+k,aux,compPii) - tables;
    while(idx < k && used[idx]) idx++;

    if(idx < k){
      res.push_back({requests[i].i,tables[idx].second});
      used[idx]=true;
      sum += p;
    }
  }

  cout << res.size() << " " << sum << endl;
  for(pii p: res){
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}