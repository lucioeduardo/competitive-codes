#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b){
  if(a.size() == b.size()){
    for(int i=0; i<a.size(); i++){
      if(a[i] != b[i]) return a[i]>b[i];
    }
    return true;
  }
  return a.size() > b.size();
}

int main(){
  int v;
  int dig[10];

  cin>>v;

  for(int i=1; i<=9; i++)
    cin>>dig[i];
  
  int m=0;
  string res = "";

  for(int i=1; i<=9; i++){
    int x = v/dig[i];
    int r = (v%dig[i]) + dig[i];

    string s = "";

    for(int j=0; j<x; j++) s += ('0'+i);
    int it=0;


    while(r > 0 && it < s.length()){
      int choice=i;
      for(int j=1; j<=9; j++){
        if(dig[j] <= r && j > choice)
          choice=j;
      }

      
      if(choice == i) break;

      r -= (dig[choice]);
      r += dig[i];

      s[it++]=(choice + '0');
    }


    if(comp(s,res)) res=s;
  }

  if(res.empty())
    cout << -1;
  else{
    cout << res << endl;
  }

  
  return 0;
}