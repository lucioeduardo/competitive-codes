#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 505
using namespace std;

int n,m,r1,c1,r2,c2;
char mapa[MAXN][MAXN];
bool seen[MAXN][MAXN];

int sX[4] = {1,-1,0,0};
int sY[4] = {0,0,-1,1};

bool valid(int x, int y){
  return !(x <= 0 || y <= 0 || x > n || y > m);
}

bool dfs(int x, int y){
  if(x == r2 && y == c2){
    if(mapa[x][y] == 'X') return true;
    if(mapa[x][y] == '.') mapa[x][y] = 'X';
  }else{
    seen[x][y] = true;
    if(mapa[x][y] == 'X') return false;
  } 
  
  for(int i=0; i<4; i++){
    int nX = x+sX[i];
    int nY = y+sY[i];

    if(valid(nX,nY) && !seen[nX][nY]){
      if(dfs(nX,nY)) return true;
    }
  }

  return false;
}


int main(){

  cin>>n>>m;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin>>mapa[i][j];
    }
    getchar();
  }

  cin>>r1>>c1>>r2>>c2;

  mapa[r1][c1] =  '.';
  bool path = dfs(r1,c1);

  cout << (path ? "YES":"NO") << endl;

  return 0;
}