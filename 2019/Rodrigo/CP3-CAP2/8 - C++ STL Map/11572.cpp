#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, x;
    map<int, int> m;
    
    cin >> t;

    while(t--) {
        int b = 0;
        int answer = 0;

        cin >> n;

        for(int i=1; i<=n; ++i) {
            cin >> x;

            b = max(b, m[x]);
            answer = max(answer, (i - b));
            m[x] = i;
        }

        cout << answer << endl;
        m.clear();
    }
    return 0;
}