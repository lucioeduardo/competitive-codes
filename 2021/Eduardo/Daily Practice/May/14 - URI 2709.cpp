#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

bool is_prime(int n){
  if(n <= 1) return false;

  for(int i=2; i*i<=n; i++){
    if(n%i == 0) return false;
  }

  return true;
}

int main(){
  int m;
  vector<int> coins;

  while(cin>>m){
    coins.clear();
    int n;

    for(int i=0; i<m; i++){
      int v;
      cin>>v;
      coins.push_back(v);
    }

    cin>>n;

    int idx=m-1;
    int sum=0;

    while(idx >= 0){
      sum += coins[idx];
      idx -= n;
    }

    if(is_prime(sum))
      cout << "You’re a coastal aircraft, Robbie, a large silver aircraft." << endl;
    else cout << "Bad boy! I’ll hit you." << endl;


  }

  return 0;
}