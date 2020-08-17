#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool is_prime(int x){
  for(int i=2; i*i<=x; i++){
    if(x % i == 0) return false;
  }

  return true;
}

bool tprime(ll x){
  if(x == 1) return false;

  ll esq=2, dir=x;

  ll sq = sqrt(x);

  if(sq*sq != x) return false;
  return is_prime(sq);
}



int main(){
  int n;

  cin>>n;

  while(n--){
    ll v;
    cin>>v;

    cout << (tprime(v) ? "YES":"NO") << endl;
  }
  
  return 0;
}