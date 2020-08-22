#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(a%b == 0) return b;
  return gcd(b, a%b);
}

int main(){
  int a,b;

  cin>>a>>b;

  int g = gcd(a,b);
  vector<int> divs;

  divs.push_back(1);
  divs.push_back(g);

  for(int i=2; i*i <= g; i++){
    if(g % i == 0){
      divs.push_back(i);
      if(i != g/i) divs.push_back(g/i);
    }
  }

  sort(divs.begin(), divs.end());

  int n;
  cin>>n;

  while(n--){
    int l,r;
    cin>>l>>r;

    int idx = upper_bound(divs.begin(), divs.end(), r) - divs.begin();

    if(idx > 0 && divs[idx-1] >= l)
      cout << divs[idx-1] << endl;
    else
      cout << -1 << endl;
  }
  
  return 0;
}