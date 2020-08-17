#include<bits/stdc++.h>
#define MAXN 110
using namespace std;

int n,m;
vector<int> emp[MAXN];
int lang[MAXN];
bool seen[MAXN];

void dfs(int x){
  seen[x] = true;

  for(int i=0; i<n; i++){
    if(i == x || seen[i]) continue;
    bool flag = false;
    for(int j=0; j<emp[x].size(); j++){
      for(int k=0; k<emp[i].size(); k++){

        if(emp[x][j] == emp[i][k]){
          flag=true;
          break;
        }
      }
    }

    if(flag) dfs(i);
  }
}

int main(){
  cin>>n>>m;

  bool zero=true;

  for(int i=0; i<n; i++){
    int k;
    cin>>k;
    while(k--){
      zero = false;
      int v;
      cin>>v;
      emp[i].push_back(v);
    }
  }

  for(int i=0; i<m; i++){
    cin >> lang[i];
  }

  int nc=0;

  for(int i=0; i<n; i++){
    if(!seen[i]){
      dfs(i);
      nc++;
    }
  }

  cout << nc - (zero == false) << endl;

  return 0;
}