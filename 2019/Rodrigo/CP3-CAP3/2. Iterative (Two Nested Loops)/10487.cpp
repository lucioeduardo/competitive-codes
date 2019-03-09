#include <bits/stdc++.h>
using namespace std;

int main() {

    int t = 0;
    int n, v[1005];

    while((cin >> n) && n) {
        for (int i=0; i<n; ++i)
            cin >> v[i];

        cout << "Case " << ++t << ":" << endl;
        int Q; cin >> Q;

        while(Q--) {
            int q; cin >> q;
            int answer = 1e9;

            for(int i=0; i<n; ++i) {
                for(int j=i + 1; j<n; ++j) {
                    if(abs((v[i] + v[j]) - q) < abs(answer - q))
                        answer = v[i] + v[j];
                }
            }
            cout << "Closest sum to " << q << " is " << answer << "." << endl;
        }
    }
    return 0;
}