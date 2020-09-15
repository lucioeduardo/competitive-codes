#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 1000100
using namespace std;

int f[MAXN],l[MAXN];

int main(){
  int k;
  string s;

  cin>>k>>s;
  int n = s.length();

  init(f,-1);

  int sum=0;
  
  for(int i=0; i<n; i++){
    if(s[i] == '1') sum++;
    if(f[sum] == -1) f[sum]=i;
    l[sum]=i;
  } 

  ll res=0;
  sum=0;

  for(int i=0; i<n; i++){
    if(k+sum > n)break;

    if(f[k+sum] != -1 && !(k == 0 && s[i] == '1')) res += (l[k+sum] - max(i,f[k+sum]) + 1);
    if(s[i] == '1') sum++;
  } 

 
  cout << res << endl;

  
  return 0;
}