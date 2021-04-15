#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int mat[9][9];
bool seen[10];

int main(){
  int n;

  cin>>n;

  for(int i=1; i<=n; i++){
    bool res=true;

    for(int i=0; i<9; i++){
      memset(seen,false,sizeof(seen));
      for(int j=0; j<9; j++){
        int v;
        cin>>v;
        mat[i][j]=v;

        if(v > 9 || v < 1 || seen[v])
          res=false;
        seen[v]=true;
      }
    }

    for(int i=0; i<9; i++){
      memset(seen,false,sizeof(seen));
      for(int j=0; j<9; j++){
        int v=mat[j][i];

        if(v > 9 || v < 1 || seen[v])
          res=false;
        seen[v]=true;
      }
    }

    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
        memset(seen,false,sizeof(seen));
        for(int k=3*i; k<3*(i+1); k++){
          for(int w=3*j; w<3*(j+1); w++){
            int v=mat[k][w];

            if(v > 9 || v < 1 || seen[v])
              res=false;
            seen[v]=true;
          }
        }
      }
    }

    cout << "Instancia " << i << endl;
    cout << (res ? "SIM": "NAO") << endl << endl;
  }
  
  return 0;
}