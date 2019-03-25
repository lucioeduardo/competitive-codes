#include <bits/stdc++.h>
using namespace std;

int n, m, t, q;
int tower[25];
int value[15];
int intersection[15];
int customers, mask;

void solve() {
    customers = mask = 0;
    for(int state=1; state<=(1 << n) - 1; ++state) {
        if(__builtin_popcount(state) == t) {
            int current = 0;

            for(int bit=0; bit < n; ++bit)
                if(state & (1 << bit))
                    current += tower[bit];

            for(int i=0; i<m; ++i) {
                int k = __builtin_popcount(state & intersection[i]);

                if(k > 1)
                    current -= ((k - 1) * value[i]);
            }

            if(customers < current) {
                customers = current;
                mask = state;
                
            } else if(customers == current) {
                int x = mask, y = state;
                int lx, ly;

                do {
                    lx = x&(-x);
                    ly = y&(-y);
                    x -= lx, y -= ly;

                } while(lx == ly);

                mask = ly < lx ? state : mask;
            }
        }
    }
}

int main() {

    int caseTest = 0;
    while(cin >> n >> t && n + t) {
        for(int i=0; i<n; ++i)
            cin >> tower[i];

        cin >> m;
        for(int i=0; i<m; ++i) {
            cin >> q;

            for(int j=0; j<q; ++j) {
                int x; cin >> x;
                intersection[i] |= (1 << (x - 1));
            }

            cin >> value[i];
        }

        solve();

        cout << "Case Number  " << ++caseTest << endl;
        cout << "Number of Customers: " << customers << endl;
        cout << "Locations recommended:";

        for(int bit=0; bit<n; ++bit)
            if((1 << bit) & mask)
                cout << " " << 1 + bit;

        cout << endl << endl;
        memset(intersection, 0, sizeof intersection);
    }
    return 0;
}