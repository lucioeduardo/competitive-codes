#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define MAXN 200020
using namespace std;

int lps[MAXN];

void calcLPS(vector<int>& pat){
  int m = pat.size();

  int len=0;
  int i=1;
  lps[0]=0;

  while(i < m){
    if(pat[i] == pat[len]){
      lps[i++] = ++len;
    }else{
      if(len > 0)
        len = lps[len-1];
      else{
        lps[i]=0;
        i++;
      }
    }

    
  }
}

int kmp(vector<int>& pat, vector<int>& str){
  int j=0, i=0;

  calcLPS(pat);

  int res=0;

  while(i < str.size()){
    if(str[i] == pat[j]){
      j++;
      i++;

      if(j == pat.size()){
        res++;
        j=lps[j-1];
      }

    }else{
      if(j>0)
        j = lps[j-1];
      else
        i++;
    }
  }

  return res;
}

int main(){

  int n,m;
  cin>>n>>m;
  vector<int> a(n),b(m), patA, patB;

  if(m == 1){
    cout << n << endl;
    return 0;
  }


  for(int i=0; i<n; i++) cin>>a[i];
  for(int i=0; i<m; i++) cin>>b[i];

  for(int i=0; i<n-1; i++) patA.push_back(a[i+1]-a[i]);
  for(int i=0; i<m-1; i++) patB.push_back(b[i+1]-b[i]);

  calcLPS(patB);

  cout << kmp(patB, patA);

  return 0;
}