#include <bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr, val) memset(arr, val, sizeof(arr))
#define ll long long
using namespace std;

map<string, vector<string>> rules = {
    {"tesoura", {"papel", "lagarto"}},
    {"papel", {"pedra", "spock"}},
    {"pedra", {"tesoura", "lagarto"}},
    {"lagarto", {"spock", "papel"}},
    {"spock", {"tesoura", "pedra"}}
};

int check(string x, string y){
  for(string s: rules[x]){
    if(s == y)
      return 1;
  }

  for(string s: rules[y]){
    if(s == x)
      return -1;
  }

  return 0;
}

int main()
{
  int n;

  cin >> n;

  while (n--){
    string a,b;
    
    cin>>a>>b;

    int res = check(a,b);

    if(res == 0) cout << "empate" << endl;
    else if(res == 1) cout << "rajesh" << endl;
    else cout << "sheldon" << endl;
  }

  return 0;
}