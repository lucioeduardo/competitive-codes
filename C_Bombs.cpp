#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define pii pair<int,int>
using namespace std;

vector<pii> bombs;

bool compare(pii a, pii b){
  return (abs(a.first) + abs(a.second)) < (abs(b.first) + abs(b.second));
}

void goX(int v){
  if(v>0) printf("1 %d %c\n", abs(v), 'R');
  else if(v < 0) printf("1 %d %c\n", abs(v), 'L');
}

void goY(int v){
  if(v>0) printf("1 %d %c\n", abs(v), 'U');
  else if(v < 0) printf("1 %d %c\n", abs(v), 'D');
}

int main(){
  int n;

  cin>>n;

  int qtd=0;

  for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
    bombs.push_back({a,b});
  
    if(a != 0) qtd += 2;
    if(b != 0) qtd+= 2;
    qtd += 2;
  }

  sort(bombs.begin(), bombs.end(), compare);

  cout << qtd << endl;

  for(int i=0; i<n; i++){
    goX(bombs[i].first);
    goY(bombs[i].second);
    cout << "2" << endl;
    goX(-bombs[i].first);
    goY(-bombs[i].second);
    cout << "3" << endl;
  }

  return 0;
}