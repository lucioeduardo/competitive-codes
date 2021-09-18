#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

string substr(string s, int start, int end){
  string res="";
  for(int i=start; i<end; i++){
    res += s[i];
  }
  return res;
}

int main(){
  string inp;

  while(cin>>inp){
    int len = inp.length();

    int equal_pos=0;
    int plus_pos=0;
    for(int i=0; i<inp.length(); i++){
      if(inp[i] == '=') equal_pos=i;
      if(inp[i] == '+') plus_pos=i;
    }

    string r = substr(inp,0,plus_pos);
    string l = substr(inp,plus_pos+1,equal_pos);
    string j = substr(inp,equal_pos+1,len);


    if(r == "R"){
      cout << stoi(j)-stoi(l) << endl;
    }else if(l == "L"){
      cout << stoi(j)-stoi(r) << endl;
    }else{
      cout << stoi(r)+stoi(l) << endl;
    }
  }
  
  return 0;
}