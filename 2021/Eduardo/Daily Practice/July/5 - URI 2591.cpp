#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  cin>>n;

  while(n--){
    string str;

    cin>>str;

    int a=0, b=0;
    bool f=true;

    for(char c: str){
      if(c == 'a'){
        if(f) a++;
        else b++;
      }

      if(c == 'k') f=false;
    }

    int x = a*b;

    printf("%c",'k');
    while(x--) cout << "a";
    cout << endl;
  }
  
  return 0;
}