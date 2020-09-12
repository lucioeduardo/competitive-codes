#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int qtd[100];

int main(){
  int t;

  cin>>t;

  while(t--){
    int n;
    cin>>n;

    init(qtd,0);

    for(int i=0; i<n; i++){
      int a;
      cin>>a;

      qtd[a]++;
    }

    int m1=-1, m2=-1;

    for(int i=0; i<100; i++){
      if(qtd[i] == 0){
        if(m2 == -1) m2=i;
        if(m1 == -1) m1=i;
      }else if(qtd[i] == 1){
        if(m1 == -1) m1=i;
      }
    }


    cout << m1+m2 << endl;
  }
  
  return 0;
}