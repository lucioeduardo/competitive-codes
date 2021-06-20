#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

map<char, int> val;

int main(){
  int n,m;

  cin>>n>>m;
  getchar();

  while(n--){
    char c;
    int x;

    scanf("%c %d ",&c,&x);

    val[c]=x;
  }

  int k, sum=0;
  cin>>k;
  getchar();

  while(k--){
    char c;
    cin>>c;

    sum += val[c];
  }

  cout << sum << endl;
  cout << (sum >= m ? "You shall pass!":"My precioooous") << endl;
  
  return 0;
}