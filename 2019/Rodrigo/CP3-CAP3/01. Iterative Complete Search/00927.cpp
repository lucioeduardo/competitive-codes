#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c[25];

ll calc(int d, int k) {
    ll current = 0, i = 0;

    while(current < k)
        current += (++i * d);

    return i;
}

ll solve(int v, int n) {
    ll answer = 0;

    for(int i=0; i<=v; ++i)
        answer += c[i] * pow(n, i);
    
    return answer;
}

int main() {

    int t; cin >> t;

    while(t--) {
        int v; cin >> v;

        for(int i=0; i<=v; ++i)
            cin >> c[i];
        
        int d, k; cin >> d >> k;

        cout << solve(v, calc(d, k)) << endl;
    }

    return 0;
}