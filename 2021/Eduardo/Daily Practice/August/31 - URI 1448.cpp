#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int t;

  cin>>t;
  getchar();

  for(int i=1; i<=t; i++){
    cout << "Instancia " << i << endl;

    int t1=0, t2=0;
    string s,a,b;


    getline(cin,s);
    getline(cin,a);
    getline(cin,b);

    int f=-1;
    for(int j=0; j<s.length(); j++){
      if(s[j] == a[j]) t1++;
      if(s[j] == b[j]) t2++;

      if(t1 != t2 && f == -1){
        f = (t1 > t2) ? 1:2;
      }
    }

    if(t1 == t2 && f == -1) cout << "empate" << endl;
    else if(t1 > t2 || (t1 == t2 && f == 1)) cout << "time 1" << endl;
    else cout << "time 2" << endl;

    cout << endl;
  }
  
  return 0;
}