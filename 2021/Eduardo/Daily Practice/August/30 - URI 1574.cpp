#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 110
using namespace std;

int v[MAXN];

int main(){
  int t;

  cin>>t;

  while(t--){
    int n;
    cin>>n;

    int res=0;

    for(int i=1; i<=n; i++){
      string s;
      cin>>s;

      int x=0;

      if(s == "LEFT"){
        x =  -1;
      }else if(s == "RIGHT"){
        x = 1;
      }else{
        string a;
        int p;

        cin>>a>>p;

        x=v[p];
      }

      v[i]=x;
      res += x;
    }
  
    cout << res << endl;
  }

  
  return 0;
}