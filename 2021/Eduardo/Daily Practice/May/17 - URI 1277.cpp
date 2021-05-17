#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

double calc_freq(string freq){
  double a=0, b=0;

  for(char c: freq){
    if(c == 'P'){
      a++;
      b++;
    }else if(c == 'A') b++;
  }

  return a/b;
}

int main(){
  int t;

  cin>>t;

  while(t--){
    int n;
    cin>>n;

    string names[n], freq[n];

    for(int i=0; i<n; i++) cin>>names[i];
    for(int i=0; i<n; i++) cin>>freq[i];

    bool f=false;

    for(int i=0; i<n; i++){
      if(calc_freq(freq[i]) < 0.75){
        if(f) cout << ' ';
        cout << names[i];
        f=true;
      }
    }

    cout << endl;
  }
  
  return 0;
}