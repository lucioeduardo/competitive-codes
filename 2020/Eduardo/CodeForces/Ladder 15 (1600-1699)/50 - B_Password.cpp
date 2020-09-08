#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;


vector<int> p;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    pi[0]=0;
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 

int main(){
  string s;

  cin>>s;

  int n = s.length();
  p = prefix_function(s);

  //for(int i=0; i<n; i++) cout << p[i] << endl;

  int v = p[n-1];
  int res= p[v-1];
  if(v == 0 ) res=0;
    
  //cout << v << " " << res << endl;
  
  for(int i=1; i<n-1; i++){
    if(p[i] == v){
        res = v;
    }
  }


  cout << (res == 0 ? "Just a legend" : s.substr(0,res)) << endl;
  
  return 0;
}

