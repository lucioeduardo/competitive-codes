#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll unsigned long long
#define MAXM 22
using namespace std;

ll mat[22][22];
int maxCol[22];

int length(ll val){
  int res=0;

  if(val==0) return 1;

  while(val > 0){
    val/=10;
    res++;
  }

  return res;
}

int main(){
  int n;
  int t=4;

  cin>>n;

  while(n--){
    cout << "Quadrado da matriz #" << t++  << ":" << endl;

    int m;
    cin>>m;

    memset(maxCol, 0, sizeof(maxCol));

    for(int i=0; i<m; i++){
      for(int j=0; j<m; j++){
        ll v;
        cin>>v;

        mat[i][j] = v*v;

        maxCol[j] = max(maxCol[j], length(mat[i][j]));
      }
    }

    for(int i=0; i<m; i++){
      for(int j=0; j<m; j++){
        if(j > 0) printf(" ");
        printf("%*llu",maxCol[j],mat[i][j]);
      }

      cout << endl;
    }

    if(n > 0) cout << endl;
  }

  
  return 0;
}