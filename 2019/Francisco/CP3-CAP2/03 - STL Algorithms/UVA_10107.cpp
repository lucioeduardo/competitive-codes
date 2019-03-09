#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<long long> v;
    long long n, m;

    while(scanf("%d", &n) != EOF){

        v.push_back(n);

        sort(v.begin(), v.end());

        m = (v.size()%2) ? v[v.size()/2] : (v[v.size()/2] + v[(v.size()/2)-1])/2;

        printf("%d\n", m);

    }


    return 0;
}