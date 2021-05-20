#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

const string max_i =  "2147483647";

bool check(string num){
  if(num.length() < max_i.length()) return true;
  if(num.length() > max_i.length()) return false;

  for(int i=0; i<num.length(); i++){
    if(num[i] > max_i[i]) return false;
    if(num[i] < max_i[i]) return true;
  }

  return true;
}

int main(){
  string s;

  while(getline(cin,s)){
    if(s.empty()) cout << "error" << endl;
    else{
      bool res = true;

      string num="";

      bool zero=false;

      for(int i=0; i<s.length(); i++){
        char add = 'x';
        if(isdigit(s[i])) { 
          add = s[i];
        }
        else if(s[i] == 'O' || s[i] == 'o') add = '0';
        else if(s[i] == 'l') add='1';
        else if(!isspace(s[i]) && s[i] != ',') res=false;


        if(num.empty() && add == '0'){
            zero=true;
            continue;
        }else if(add != 'x'){
          num += add;
        }
      }

      
      if(num.empty() && zero) num = "0";
      //cout << res << " " << num << endl;
      res = res && check(num) && !num.empty();

      if(res) cout << stoi(num) << endl;
      else cout << "error" << endl;

    }
  }

  return 0;
}