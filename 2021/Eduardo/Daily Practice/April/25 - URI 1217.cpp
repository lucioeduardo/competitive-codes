#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int n,d=1;

  cin>>n;

  double s_p=0, s_k=0;

  for(int i=0; i<n; i++){
    double v; 

    cin>>v;

    string fruits;
    
    getchar();
    getline(cin, fruits);

    int q=1;

    for(char c: fruits){
      if(c == ' ') q++;
    }

    s_p += v;
    s_k += q;

    printf("day %d: %d kg\n", d++, q);
  }

  printf("%.2lf kg by day\n", s_k/n);
  printf("R$ %.2lf by day\n", s_p/n);
  
  return 0;
}