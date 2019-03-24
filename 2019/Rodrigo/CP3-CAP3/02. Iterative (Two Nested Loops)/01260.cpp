#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;

    while(t--)  {
        int n; cin >> n;
        int v[n];

        for(int i=0; i<n; ++i)
            cin >> v[i];

        int answer = 0;
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j)
                answer += v[i] >= v[j];
        }

        cout << answer << endl;
    }
    return 0;
}