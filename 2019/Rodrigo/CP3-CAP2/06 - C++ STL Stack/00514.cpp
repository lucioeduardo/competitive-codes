// 514 - Rails
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while((cin >> n) && n)
    {
        int x;
        int v[n];

        while((cin >> x) && x)
        {
            v[0] = x;

            for(int i=1; i<n; ++i)
                cin >> v[i];

            int index = 0;
            stack<int> p;

            for(int i=1; i<=n; ++i) {
                p.push(i);

                while(!p.empty() && v[index] == p.top()) {
                    ++index;
                    p.pop();
                }
            }
            cout << (index == n ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
    return 0;
}