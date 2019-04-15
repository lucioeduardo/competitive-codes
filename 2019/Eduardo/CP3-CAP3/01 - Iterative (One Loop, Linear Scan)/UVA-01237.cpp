#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

string maker[MAXN];
double l[MAXN], h[MAXN];

string find(double v, int n){
    string res = "";
    for(int i=0; i<n; i++){
        if(l[i] <= v && h[i] >= v){
            if(res.empty()) res = maker[i];
            else return "UNDETERMINED";
        }
    }
    return res.empty() ? "UNDETERMINED" : res;
}
int main(){
    int t;

    scanf("%d",&t);

    for(int i=0; i<t; i++){
        int n;
        scanf("%d",&n);
        
        for(int j = 0; j < n; j++){
            cin>>maker[j]>>l[j]>>h[j];
        }

        int q;
        scanf("%d",&q);

        for(int j=0; j<q; j++){
            double v;
            scanf("%lf",&v);

            cout << find(v,n) << endl;
        }
        
        if(i < t-1) cout<<endl;
    }    

    return 0;
}