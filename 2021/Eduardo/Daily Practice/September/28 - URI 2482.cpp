#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

map<string, string> dict;

int main(){
  int n, m;

  cin>>n;
  getchar();

  while(n--){
    string lang, word;

    getline(cin,lang);
    getline(cin,word);

    dict[lang] = word;
  }

  cin>>m;
  getchar();

  while(m--){
    string name, lang;

    getline(cin,name);
    getline(cin, lang);

    cout << name << endl;
    cout << dict[lang] << endl << endl;
  }
  
  return 0;
}