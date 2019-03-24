#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;

        bool found = false;

        for(int i=-100; i<=100 && !found; ++i) {
            for(int j=i+1; j<=100; ++j) {
                int k = a - (i + j);

                if(k <= j) continue;
                if(i * j * k != b) continue;
                if(i * i + j * j + k * k != c) continue;

                cout << i << " " << j << " " << k << endl;
                found = true;
                break;
            }
        }

        if(!found)
            cout << "No solution." << endl;
    }
    return 0;
}