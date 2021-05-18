#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int f[26];

int main(){
  int n;

  cin>>n;
  string s;

  getchar();


  while(n--){
    //cout << n << endl;

    getline(cin,s);
    memset(f,0,sizeof(f));

    for(char c: s){
      f[(c-'A')]++;
    }

    bool res=true;

    string a,b;

    getline(cin,a);
    getline(cin,b);

    for(char c: a){
      int x = c-'A';
      f[x]--;
      if(f[x] < 0) res=false;
    }

    for(char c: b){
      int x = c-'A';
      f[x]--;
      if(f[x] < 0) res=false;
    }

    if(res == false){
      cout << "CHEATER" << endl;
      continue;
    }

    for(int i=0; i<26; i++){
      //cout << f[i] << endl;
      char c = ('A'+i);
      while(f[i]--){
        cout << c;
      }
    }

    cout << endl;

  }
  
  return 0;
}