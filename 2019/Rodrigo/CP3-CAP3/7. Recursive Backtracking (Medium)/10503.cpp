#include <bits/stdc++.h>
using namespace std;

int n, m;
int q0[2], qf[2];
int x[20], y[20];

bool solve(int space, int mask, int u) {
    
    if(space == n)
        return u == qf[0];

    for(int i=0; i<m; ++i) {
        if((x[i] == u) && !(mask & (1 << i))) {
            if(solve(space + 1, mask | (1 << i), y[i]))
                return true;
        }
        if((y[i] == u) && !(mask & (1 << i))) {
            if(solve(space + 1, mask | (1 << i), x[i]))
                return true;
        }
    }

    return false;
}

int main() {

    while(cin >> n >> m) {

        cin >> q0[0] >> q0[1];
        cin >> qf[0] >> qf[1];

        for(int i=0; i<m; ++i)
            cin >> x[i] >> y[i];

        cout << (solve(0, 0, q0[1]) ? "YES" : "NO") << endl;
    }
    return 0;
}