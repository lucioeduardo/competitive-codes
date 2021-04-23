#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s;
  
  while(getline(cin,s)){
    string word = "";

    vector<string> words;

    for(char c: s){
      if(c == ' '){
        words.push_back(word);
        word = "";
      }else{
        word += c;
      }
    }

    words.push_back(word);

    char prev = ' ';
    bool f=false;
    int res=0;

    for(string w: words){
      if(tolower(w[0]) == prev){
        if(!f) res++;
        f=true;
      }else{
        f=false;
        prev = tolower(w[0]);
      }
    }

    cout << res << endl;
  }
  
  return 0;
}