#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100100
#define pii pair<int,int>
using namespace std;

pii tasks[MAXN];

int main(){
  int n;

  while(cin>>n){
    for(int i=0; i<n; i++){
      int a,b;
      cin>>a>>b;

      tasks[i] = {a,b};
    }

    sort(tasks, tasks+n);

    int t=0;

    for(int i=0; i<n; i++){
      pii p = tasks[i];
      
      t = max(t+p.second, p.first+p.second);
    }

    cout << t << endl;
  }
  
  return 0;
}