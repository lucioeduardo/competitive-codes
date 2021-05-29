#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n;

  while(cin>>n){
    int s=n/2;

    for(int v=1; v<=n; v+=2){
      
      string str = "";
      for(int i=0;i<v;i++)
        str+= '*';

      int l = str.length()+s;

      printf("%*s",l, str.c_str());

      cout<<endl;
      s--;
    }

    s = n/2;

    printf("%*s\n",1+s,"*");
    printf("%*s\n\n",2+s,"***");

  }

  return 0;
}