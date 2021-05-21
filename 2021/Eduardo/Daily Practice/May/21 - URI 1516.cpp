#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,m,a,b;

  while(cin>>n>>m && n!=0){
    vector<string> img(n);

    for(int i=0; i<n; i++){
      cin>>img[i];
    }

    cin>>a>>b;

    int f_n = a/n, f_m = b/m;

    vector<string> res;

    for(int i=0; i<n; i++){
      string act="";

      for(int j=0; j<m; j++){
        for(int k=0; k<f_m; k++){
          act += img[i][j];
        }
      }

      for(int k=0;k<f_n;k++){
        cout << act << endl;
      }
    }

    cout << endl;
  }

  


  
  return 0;
}