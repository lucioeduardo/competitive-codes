#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define pii pair<int,int>
using namespace std;

vector<int> b1, b2;
int wSum=0, sum=0;
int it1=0, it2=0;

bool compare(int a, int b) {
  return a > b;
}

void addb1(){
  wSum -= b1[it1++];
  sum+=1;
}

void addb2(){
  wSum -= b2[it2++];
  sum+=2;
}

int main(){
  int n;

  cin>>n;

  for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
    if(a == 1) b1.push_back(b);
    else b2.push_back(b);

    wSum += b;
  }

  sort(b1.begin(),b1.end(),compare);
  sort(b2.begin(),b2.end(),compare);

  while(sum < wSum){
    if(it1 == b1.size()){
      addb2();
    }else if(it2 == b2.size()){
      addb1();
    }else{
      if(wSum-b1[it1] <= sum+1){
        sum++;break;
      }
      int sb1 = b1[it1] + ((it1 < b1.size()-1) ? b1[it1+1] : 0);
    
      if(sb1 > b2[it2]){
        addb1();
      }else{
        addb2();
      }
    }
  }

  cout << sum << endl;

  

  return 0;
}