#include<bits/stdc++.h>
#define MOD 1000000007
#define init(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
    double a,b;

    cin>>a>>b;

    if(a > b) swap(a,b);

    int n = ceil(a*b/(a*(b-a)));

    cout << n << endl;

    return 0;
}