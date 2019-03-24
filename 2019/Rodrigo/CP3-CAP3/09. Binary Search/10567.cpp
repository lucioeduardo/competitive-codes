#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> ord[256];

    for(int i=0; s[i]; ++i)
        ord[s[i]].push_back(i);

    int q; cin >> q;
    string serial;

    while(q--) {
        cin >> serial;
        bool found = true;
        int q0 = -1, qf = -1;

        for(int i=0; serial[i]; ++i) {
            auto pos = lower_bound(ord[serial[i]].begin(), ord[serial[i]].end(), qf + 1);

            if(pos != ord[serial[i]].end()) {
                qf = *pos;

                if(q0 == -1)
                    q0 = qf;

                continue;
            }
            
            found = false;
        }

        if(found)
            printf("Matched %d %d\n", q0, qf);
        else
            printf("Not matched\n");
    }
    return 0;
}