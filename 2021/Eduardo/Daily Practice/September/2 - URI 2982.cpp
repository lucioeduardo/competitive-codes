#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,v=0,g=0;

  cin>>n;getchar();

  while(n--){
    char c;
    int value;

    cin>>c>>value;

    if(c == 'V') v+=value;
    else g+=value;
  }

  if(v >= g) cout << "A greve vai parar." << endl;
  else cout << "NAO VAI TER CORTE, VAI TER LUTA!" << endl;
  
  return 0;
}