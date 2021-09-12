#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 15
using namespace std;

int candidates[MAXN];

int main(){
  int n;

  cin>>n;

  ll votes=0;

  for(int i=0; i<n; i++){
    cin>>candidates[i];
    votes += candidates[i];
  }

  sort(candidates, candidates+n);

  int first = candidates[n-1];
  int second = candidates[n-2];

  bool op1 = (first*100/votes >= 45);
  bool op2 = (first*100/votes >= 40) && (first*10 >= second*10 + votes);
  
  if(first > second && (op1 || op2)) cout << "1" << endl;
  else cout << "2" << endl;
  
  return 0;
}