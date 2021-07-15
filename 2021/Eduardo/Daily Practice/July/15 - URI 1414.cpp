#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  int t,n;

  while(cin>>t>>n && t!=0){
    string s;
    int p;

    int p_emp=0;
    int total=0;

    for(int i=0; i<t; i++){
      cin>>s>>p;

      total += p;
      p_emp += (p%3);
    }

    p_emp += (p_emp%2);
    while((total - p_emp)%3 != 0) p_emp += 2;

    int num_emp = p_emp/2;
    int num_v = (total - p_emp)/3;

    if(num_emp + num_v < n){
      int v = n - (num_emp + num_v);

      num_emp += 3*v;
      num_v -= 2*v;
    }

    cout << num_emp << endl;
  }
  
  return 0;
}