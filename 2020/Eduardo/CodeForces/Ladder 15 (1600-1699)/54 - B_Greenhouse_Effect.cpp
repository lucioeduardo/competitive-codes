#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define pid pair<int,double>
using namespace std;

vector<pid> plants;
vector<int> stacks;

bool compare(pid a, pid b){
  return a.second < b.second;
}

int main(){
  int n,m;

  cin>>n>>m;

  for(int i=0; i<n; i++){
    int a;
    double v;
    cin>>a>>v;

    plants.push_back({a,v});
  }

  sort(plants.begin(), plants.end(), compare);

  for(int i=0;i<n; i++){
    int v = plants[i].first;

    vector<int>::iterator it = upper_bound(stacks.begin(), stacks.end(), v);

    if(it == stacks.end())
      stacks.push_back(v);
    else
      *it=v;
  }

  cout << n-stacks.size() << endl;

  return 0;
}