#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define pii pair<int,int>
using namespace std;

int freq[255];

bool compare(pii a, pii b){
  if(a.second != b.second)
    return a.second < b.second;
  else return a.first > b.first;
}

int main(){
  string s;
  bool f=true;

  while(cin>>s){
    memset(freq,0,sizeof(freq));

    for(char c: s){
      freq[c]++;
    }

    vector<pii> res;

    for(int i=0; i<255;i++){
      if(freq[i]){
        res.push_back({i,freq[i]});
      }
    }
    
    sort(res.begin(), res.end(), compare);

    if(!f) cout << endl;
    f=false;
    for(pii p: res){
      cout << p.first << " " << p.second << endl;
    }
     
  }

  return 0;
}