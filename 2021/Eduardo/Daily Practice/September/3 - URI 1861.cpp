#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define pis pair<string,int>
using namespace std;

map<string,int> res;

int main(){
  string a,b;

  while(cin>>a>>b){
    res[a]++;
    res[b]=-999999;
  }

  cout << "HALL OF MURDERERS" << endl;

  for(pis p: res){
    if(p.second > 0){
      cout << p.first << " " << p.second << endl;
    }
  }
  
  return 0;
}