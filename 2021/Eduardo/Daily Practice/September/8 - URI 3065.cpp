#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,t=1;

  while(cin>>n && n!=0){
    getchar();
    int a,b;
    char op;

    cin>>a;
    n--;

    while(n--){
      cin >> op >> b;

      if(op == '+') a += b;
      else a-=b;
    }

    cout << "Teste " << t++ << endl;
    cout << a << endl << endl;

    
  }
  
  return 0;
}