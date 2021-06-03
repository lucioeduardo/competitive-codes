#include <bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr, val) memset(arr, val, sizeof(arr))
#define ll long long
#define T 3
using namespace std;



int mod;

void mult_mat(ll a[T][T], ll b[T][T]){
  ll res[T][T];

  for(int i=0; i<T; i++){
    for(int j=0; j<T; j++){
      ll v=0;

      for(int k=0; k<T; k++){
        v += (a[i][k]*b[k][j])%mod;
      }
      res[i][j]=v%mod;
    }
  }

  for(int i=0; i<T; i++)
    for(int j=0; j<T; j++)
      a[i][j] = res[i][j];
}

void pow_mat(ll a[T][T], int n){
  ll res[T][T] = {{1,0,0},{0,1,0},{0,0,1}};

  while(n>0){
    if(n%2)
      mult_mat(res,a);
    mult_mat(a,a);
    n/=2;
  }

  for(int i=0; i<T; i++)
    for(int j=0; j<T; j++)
      a[i][j] = res[i][j];
}

int main(){
  int n,t=1;

  while(cin>>n>>mod && !(n==0 && mod==0)){
    ll mat[T][T] = {{1, 1, 1},
                 {1, 0, 0},
                 {0,0,1},};

    pow_mat(mat, n-1);

    int res;

    if(n < 2) res=1;
    else
      res =  (mat[0][0] + mat[0][1] + mat[0][2])%mod;

    printf("Case %d: %d %d %d\n", t++, n, mod, res);

  }

  return 0;
}