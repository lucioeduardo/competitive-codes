#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 100100
using namespace std;

ll v[MAXN], sum[MAXN], res_l[MAXN], res_r[MAXN];
string name[MAXN];

int main(){
  int n;

  while(cin>>n && n != 0){
    for(int i=0; i<n; i++){
      string s;
      cin>>s;

      name[i]=s;

      int val=0;
      for(char c: s){
        val += c;
      }

      v[i]=val;
      
      if(i > 0) sum[i] = sum[i-1] + v[i];
      else sum[i] = v[i];
    }

    res_l[0] = v[0];
    for(int i=1; i<n ;i++){
      res_l[i] = res_l[i-1] + sum[i-1] + v[i];
    }

    sum[n-1] = v[n-1];
    for(int i=n-2; i>=0; i--){
      sum[i] = v[i] + sum[i+1];
    }

    res_r[n-1] = v[n-1];
    for(int i=n-2; i>=0 ;i--){
      res_r[i] = res_r[i+1] + sum[i+1] + v[i];
    }

    bool f = true;

    for(int i=0; i<n-1; i++){
      if(res_l[i] == res_r[i+1]){
        cout << name[i] << endl;
        f=false;
        break;
      }
    }

    if(f) cout << "Impossibilidade de empate." << endl;
  }
  
  return 0;
}