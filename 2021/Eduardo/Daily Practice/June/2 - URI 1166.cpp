#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 55
using namespace std;

int topo[55];
int res[55];

bool isPerfectSquare(long double x)
{
    if (x >= 0) {
        long long root = sqrt(x);         
        return (root * root == x);
    }
    return false;
}

int main(){
  int s=0;
  int i=0;

  while(s < MAXN){
    bool f=true;

    for(int j=0;j<s;j++){
      if(isPerfectSquare(i+topo[j])){
        topo[j]=i;
        f=false;
        break;
      }
    }

    if(f) {
      res[s]=i-1;
      topo[s++]=i;
    }

    i++;
  }

  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;

    cout << res[n] << endl;
  }

  return 0;
}