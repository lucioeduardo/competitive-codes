#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  int m=0,f=0;

  while(n--){
    string s;
    char c;

    cin>>s>>c;

    if(c == 'F') f++;
    else m++;
  }

  cout << m << " carrinhos" << endl;
  cout << f << " bonecas" << endl; 
  
  return 0;
}