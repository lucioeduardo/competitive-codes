#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int ch[100];

int main(){
  
  for(int i=0;i<6;i++){
    int v;
    cin>>v;
    ch[v]++;
  }

  int res=0;

  for(int i=0;i<6;i++){
    int v;
    cin>>v;
    if(ch[v]) res++;
  }


  if(res == 3) cout << "terno" << endl;
  else if(res == 4) cout << "quadra" << endl;
  else if(res == 5) cout << "quina" << endl;
  else if(res == 6) cout << "sena" << endl;
  else cout << "azar" << endl;
  
  return 0;
}